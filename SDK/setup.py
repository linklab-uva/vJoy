import os
import re
import sys
import platform
import subprocess
import os
from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
from distutils.version import LooseVersion
#Environment Variables we respect:

'''
CMAKE_GENERATOR: sets which build toolchain CMake will use.  Defaults to 'Visual Studio 15 2017 Win64'

'''

class CMakeExtension(Extension):
    def __init__(self, name, sourcedir=''):
        Extension.__init__(self, name, sources=[])
        self.sourcedir = os.path.abspath(sourcedir)


class CMakeBuild(build_ext):
    def run(self):
        try:
            out = subprocess.check_output(['cmake', '--version'])
        except OSError:
            raise RuntimeError("CMake must be installed to build the following extensions: " +
                               ", ".join(e.name for e in self.extensions))

        if platform.system() == "Windows":
            cmake_version = LooseVersion(re.search(r'version\s*([\d.]+)', out.decode()).group(1))
            if cmake_version < '3.1.0':
                raise RuntimeError("CMake >= 3.1.0 is required")
        else:
            raise RuntimeError("Currently, only Microsoft Windows is supported")

        for ext in self.extensions:
            self.build_extension(ext)

    def build_extension(self, ext):
        extdir = os.path.abspath(os.path.dirname(self.get_ext_fullpath(ext.name)))
        cmake_args = [ '-G' + os.getenv('CMAKE_GENERATOR', 'Visual Studio 15 2017 Win64'),  
                      '-DBUILD_PYTHON_BINDING=ON']

        cfg = 'Release'
        build_args = ['--config', cfg]

        if platform.system() == "Windows":
            cmake_args += ['-DCMAKE_LIBRARY_OUTPUT_DIRECTORY_{}={}'.format(cfg.upper(), extdir)]
            #build_args += ['--', '/m']
        else:
            raise RuntimeError("Currently, only Microsoft Windows is supported")
            #build_args += ['--', '-j2']

        env = os.environ.copy()
        env['CXXFLAGS'] = '{} -DVERSION_INFO=\\"{}\\"'.format(env.get('CXXFLAGS', ''),
                                                              self.distribution.get_version())
        if not os.path.exists(self.build_temp):
            os.makedirs(self.build_temp)
        subprocess.check_call(['cmake', ext.sourcedir] + cmake_args, cwd=self.build_temp, env=env)
        subprocess.check_call(['cmake', '--build', '.'] + build_args, cwd=self.build_temp)

setup(
    name='pyvjoy',
    version='1.0.0',
    author='Trent Weiss',
    author_email='ttw2xk@virginia.edu',
    description='A python binding for vJoy',
    long_description='',
    ext_modules=[CMakeExtension('pyvjoy')],
    cmdclass=dict(build_ext=CMakeBuild),
    zip_safe=False,
)
