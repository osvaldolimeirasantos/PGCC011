import ctypes

libhello = ctypes.cdll.LoadLibrary("./TriplaModularizacao.so")
libhello.main()