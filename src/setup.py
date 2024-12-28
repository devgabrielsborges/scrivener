from setuptools import setup, Extension
from Cython.Build import cythonize

extensions = [
    Extension(
        "main",  # Nome do módulo (gerará um binário "main")
        ["main.pyx"],  # Arquivo fonte
        libraries=["task_operations", "menu"],  # Bibliotecas externas
        extra_compile_args=["-O2"],  # Opções de otimização
    )
]

setup(
    name="main",
    ext_modules=cythonize(extensions, compiler_directives={"language_level": "3"}),
)
