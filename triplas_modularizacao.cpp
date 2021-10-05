#include <omp.h>
#include <stdio.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t
#include <Python.h>


using namespace std;

struct DLLInitialization
{
	DLLInitialization(){
		int pid;
		#ifdef _WIN32
 		   pid = _getpid();
		#else
		   pid = getpid();       
		#endif 
		std::cerr << " [TRACE] Python module DLL loaded by process PID = <"
				  << pid << "> "
				  << std::endl;
		std::cerr << " [TRACE] Attach the debugger with: $ gdb -pid=" << pid << "\n";
	}
	~DLLInitialization(){
		std::cerr << " [TRACE] DLL native DLL unloaded OK." << std::endl;
	}	
};

DLLInitialization dllinit_hook;

/** ======== Lista de funções expostas ao Python =========== */
PyObject*
Main(PyObject* self, PyObject* args);

static PyMethodDef ModuleFunctions [] =
{
	{ "Main", Main, METH_VARARGS,
	  "Documentation or docstring of function Main." }
	// Valor do Sentinel usado para indicar o fim da lista de funções.
	// Todas as listas de funções devem terminar com este valor.
	,{nullptr, nullptr, 0, nullptr}									
};

/* Definição de módulo */
static struct PyModuleDef ModuleDefinitions 
{
	PyModuleDef_HEAD_INIT,
	
	// Nome do módulo como string
	"triplas_modularizacao",
	// Documentação do módulo (docstring)
	"A sample C++ native-code module for python3.",
	-1,
	// Funções expostas ao módulo
	ModuleFunctions
};

/** Função de inicialização do módulo: deve ter este esquema de nome
 * PyInit_ <ModuleName> onde ModuleName é o mesmo nome de base do
 * biblioteca compartilhada ModuleName.so (no Linux) ou ModuleName.pyd (no Windows)
 */
PyMODINIT_FUNC PyInit_modulo(void)
{
	Py_Initialize();
	PyObject* pModule = PyModule_Create(&ModuleDefinitions);
	PyModule_AddObject(pModule, "version", Py_BuildValue("s", "version 0.1-Alpha"));
	return pModule;
}

void tripla_pitagorica_c(int quantidade)
{
 
    // inicializando as variáveis que vão compor o terno pitagórico
    int a, b, c = 0;
 
    // inicializando m e n que vão ser utilizadas para realizar a interação dos valores.
    int m = 2;
    int n;
    int contador = 0; // a variável contador, será utilizada para trazer o total de triplas pitagóricas existentes.
    int parada = 0;
    //a tripla pitagórica compreende que: a<b<c , desta forma como c é o maior valor entre as outras 2 partes,
    // verificamos se c é menor que o valor da quantidade inserida pelo usuário.
    while (parada == 0) {
        // nesse loop, verificamos se n é menor que m, caso a condição seja verdadeira, o cálculo será executado.
        for (n=1; n < m; ++n) {
            //cálculo para obter os valores de a,b e c
            a = (m * m) - (n * n);
            b = 2 * (m * n);
            c = (m * m) + (n * n);
        
            // com o novo valor de c, verificamos se c é maior que o valor da quantidade inserida.
            if (c > quantidade)
                parada = 1; //caso a condição seja verdadeira, a execução é encerrada e o valor do contador é apresentado ao usuário.
            
            ++contador; // a cada tripla encontrada o contador é incrementado +1.
        }
        m++;
    }
    printf("%d", contador);
}
 
// Driver Code
PyObject* Main(PyObject* self, PyObject* args){
{
    clock_t t; //variável para armazenar tempo
    t = clock(); //armazena tempo

    int quantidade = 100000000;
    omp_set_num_threads(4); // Configura o número de treads
    #pragma omp parallel // Inicia uma seção paralela
    {
        tripla_pitagorica_c(quantidade);
        printf("- Hello, World! I'm thread %d.\n", omp_get_thread_num());
        
    } // Fim da seção paralela


    t = clock() - t; //tempo final - tempo inicial
    //imprime o tempo na tela
    printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC))); //conversão para double

    Py_RETURN_NONE;
}


