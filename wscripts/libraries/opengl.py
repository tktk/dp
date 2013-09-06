# -*- coding: utf-8 -*-

from wscripts import common
from .builder import buildPartialLibrary

def build(
    _ctx,
    _sourcesSet,
    _librariesSet,
):
    setupSources = set()
    if _ctx.osName == common.LINUX:
        setupSources |= {
            'opengl_setup',
        }

    sources = {
        'glcontext',
        'glcontextinfo',
    }

    osSources = {
        'glcontext',
    }

    libraries = set()
    if _ctx.osName == common.LINUX:
        libraries |= {
            'GL',
        }

    useModules = {
        'window',
    }
    if _ctx.osName == common.LINUX:
        useModules = {
            'common',
        }

    buildPartialLibrary(
        _ctx,
        _sourcesSet,
        _librariesSet,
        'opengl',
        setupSources = setupSources,
        sources = sources,
        osSources = osSources,
        libraries = libraries,
        useModules = useModules,
    )
