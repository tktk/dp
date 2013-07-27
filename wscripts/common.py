# -*- coding: utf-8 -*-

import os.path

APPNAME = 'dp'

X86 = 'x86'
AMD64 = 'amd64'

LINUX = 'linux'
WINDOWS = 'windows'

DEBUG = 'debug'
RELEASE = 'release'

COMMON = 'common'

BUILD_DIR = 'build'

INCLUDE_DIR = 'inc'

IMPL_DIR = 'impl'
IMPL_INCLUDE_DIR = os.path.join(
    IMPL_DIR,
    INCLUDE_DIR,
)
SOURCE_DIR = os.path.join(
    IMPL_DIR,
    'src',
)

IMPL_PACKAGE_DIR = APPNAME + IMPL_DIR

def generatePartialLibraryName( _name ):
    return APPNAME + '_' + _name

def generateCompositeLibraryName():
    return APPNAME

def buildPartialLibrary(
    _ctx,
    _sourcesSet,
    _librariesSet,
    _target,
    _includes,
    _libpath,
    _setupSources,
    _sources,
    _libraries,
    _useModules,
):
    if _sourcesSet is not None:
        _sourcesSet |= _sources

    if _librariesSet is not None:
        _librariesSet |= _libraries

    _buildObject(
        _ctx,
        _target,
        _includes,
        _libpath,
        _setupSources | _sources,
        _libraries,
        _useModules,
    )

def buildCompositeLibrary(
    _ctx,
    _target,
    _includes,
    _libpath,
    _sources,
    _libraries,
    _useModules,
):
    _buildObject(
        _ctx,
        _target,
        _includes,
        _libpath,
        _sources,
        _libraries,
        _useModules,
    )

def _buildObject(
    _ctx,
    _target,
    _includes,
    _libpath,
    _sources,
    _libraries,
    _useModules,
):
    _ctx.shlib(
        target = _target,
        source = _sources,
        lib = _libraries,
        use = _useModules,
        includes = _includes,
        libpath = _libpath,
    )
