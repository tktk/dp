# -*- coding: utf-8 -*-

from wscripts import common

import os.path

def buildPartialLibrary(
    _ctx,
    _sourcesSet,
    _librariesSet,
    _libraryName,
    setupSources = set(),
    sources = set(),
    osSources = set(),
    libraries = set(),
    useModules = set(),
):
    common.buildPartialLibrary(
        _ctx,
        _sourcesSet,
        _librariesSet,
        common.generatePartialLibraryName( _libraryName ),
        _generateIncludes( _ctx ),
        _generateLibpath( _ctx ),
        _generateOsSources(
            _ctx,
            setupSources,
            _libraryName,
        ),
        _generateCommonSources(
            sources,
            _libraryName,
        ) | _generateOsSources(
            _ctx,
            osSources,
            _libraryName,
        ),
        libraries,
        { common.generatePartialLibraryName( i ) for i in useModules }
    )

def buildCompositeLibrary(
    _ctx,
    _setupSources,
    _sources,
    _libraries,
):
    common.buildCompositeLibrary(
        _ctx,
        common.generateCompositeLibraryName(),
        _generateIncludes( _ctx ),
        _generateLibpath( _ctx ),
        _generateSourcesForCompositeLibrary(
            _ctx,
            _setupSources,
        ) | _sources,
        _libraries,
        set(),
    )

def _generateSources(
    _sources,
    _libraryName,
):
    return {
        _generateSourcePath(
            os.path.join(
                _libraryName,
                i,
            )
        )
        for i in _sources
    }

def _generateSourcePath( _path ):
    return os.path.join(
        common.SOURCE_DIR,
        common.IMPL_PACKAGE_DIR,
        _path + '.cpp',
    )

def _generateCommonSources(
    _sources,
    _libraryName,
):
    return _generateSources(
        _sources,
        os.path.join(
            common.COMMON,
            _libraryName,
        ),
    )

def _generateOsSources(
    _ctx,
    _sources,
    _libraryName,
):
    return _generateSources(
        _sources,
        os.path.join(
            _ctx.osName,
            _libraryName,
        ),
    )

def _generateSourcesForCompositeLibrary(
    _ctx,
    _sources,
):
    return _generateSources(
        _sources,
        _ctx.osName,
    )

def _generateIncludes( _ctx ):
    includes = [
        common.INCLUDE_DIR,
        common.IMPL_INCLUDE_DIR,
    ]

    return includes

def _generateLibpath( _ctx ):
    libpath = [
    ]

    return libpath
