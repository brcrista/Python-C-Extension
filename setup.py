from distutils.core import setup, Extension

spam_module = Extension('spam', sources=['spammodule.c'])

setup(
    name='spam',
    version='1.0.0',
    ext_modules=[spam_module])
