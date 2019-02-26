
from setuptools import setup
from setuptools import Extension
from setuptools import find_packages

from distutils.command.build import build as BaseBuildCommand
from setuptools.command.install import install as BaseInstallCommand
from setuptools.command.build_ext import build_ext as BaseBuildExtCommand

setup(
    name='TemplatePythonPackage',
    version='0.0.1',
    description='Template package for various projects',
    author='Wilbert Pumacay',
    author_email='wpumacay@gmail.com',
    url='https://github.com/wpumacay/sample_python_package',
    packages=find_packages(),
    license='MIT',
    install_requirements=[
        'numpy'
    ],
    keywords='python package template'
)