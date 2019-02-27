
# setup.py script adapted from pybind11 cmake_example:
# https://github.com/pybind/cmake_example/blob/master/setup.py

import os
import sys
import subprocess

from setuptools import setup
from setuptools import Extension
from setuptools import find_packages

from setuptools.command.install import install as BaseInstallCommand
from setuptools.command.build_ext import build_ext as BaseBuildExtCommand

def buildSampleBindings( sourceDir, buildDir, cmakeArgs, buildArgs, env ):
    if not os.path.exists( buildDir ) :
        os.makedirs( buildDir )

    print( 'cmakeArgs: ' )
    print( cmakeArgs )

    print( 'buildArgs: ' )
    print( buildArgs )

    print( 'sourceDir: ' )
    print( sourceDir )

    print( 'buildDir: ' )
    print( buildDir )

    print( 'env: ' )
    print( env )

    subprocess.call( ['cmake', sourceDir] + cmakeArgs, cwd=buildDir, env=env )
    subprocess.call( ['cmake', '--build', '.'] + buildArgs, cwd=buildDir )

class CMakeExtension( Extension ) :

    def __init__( self, name, sourceDir, resourcesDir ) :
        super( CMakeExtension, self ).__init__( name, sources=[] )
        self.sourceDir = os.path.abspath( sourceDir )
        self.resourcesDir = os.path.abspath( resourcesDir )

class BuildBindingsCommand( BaseBuildExtCommand ) :

    def run( self ) :
        try:
            _ = subprocess.check_output( ['cmake', '--version'] )
        except OSError:
            raise RuntimeError( 'CMake must be installed to build the following extensions: ' +
                                ', '.join( e.name for e in self.extensions ) )

        for _extension in self.extensions :
            self.build_extension( _extension )

    def build_extension( self, extension ) :
        _extensionFullPath = self.get_ext_fullpath( extension.name )
        _extensionDirName = os.path.dirname( _extensionFullPath )
        _extensionDirPath = os.path.abspath( _extensionDirName )

        _cfg = 'Debug' if self.debug else 'Release'
        _buildArgs = ['--config', _cfg, '--', '-j4']
        _cmakeArgs = ['-DCMAKE_LIBRARY_OUTPUT_DIRECTORY=' + _extensionDirPath,
                      '-DPYTHON_EXECUTABLE=' + sys.executable,
                      '-DCMAKE_BUILD_TYPE=' + _cfg]

        _env = os.environ.copy()
        _env['CXXFLAGS'] = '{} -DVERSION_INFO=\\"{}\\"'.format( _env.get( 'CXXFLAGS', '' ),
                                                                self.distribution.get_version() )

        _sourceDir = extension.sourceDir
        _buildDir = self.build_temp

        buildSampleBindings( _sourceDir, _buildDir, 
                             _cmakeArgs, _buildArgs, 
                             _env )

## class InstallCommand( BaseInstallCommand ) :
##     

print( 'packages: ', find_packages() )

setup(
    name                    = 'TemplatePythonPackage',
    version                 = '0.0.1',
    license                 = 'MIT',
    description             = 'Template package for various projects',
    author                  = 'Wilbert Pumacay',
    author_email            = 'wpumacay@gmail.com',
    url                     = 'https://github.com/wpumacay/sample_python_package',
    keywords                = 'package template',
    packages                = find_packages(),
    package_data            = {
                                'sample_py' : [ '../res/xml/*.xml',
                                                '../res/json/*.json',
                                                '../res/imgs/*.png' ]
                              },
    install_requires        = [
                                'numpy'
                              ],
    ext_modules             = [
                                CMakeExtension( 'pysample', '.', 'res' )
                              ],
    cmdclass                = { 
                                'build_ext': BuildBindingsCommand 
                              },
    zip_safe                = False
)