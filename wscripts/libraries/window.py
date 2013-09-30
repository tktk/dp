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
            'window_setup',
        }

    sources = {
        'window',
        'windowinfo',
    }

    osSources = {
        'window',
    }

    libraries = set()
    if _ctx.osName == common.LINUX:
        libraries |= {
            'pthread',
        }

    useModules = set()
    if _ctx.osName == common.LINUX:
        useModules = {
            'common',
            'xlib',
        }

    buildPartialLibrary(
        _ctx,
        _sourcesSet,
        _librariesSet,
        'window',
        setupSources = setupSources,
        sources = sources,
        osSources = osSources,
        libraries = libraries,
        useModules = useModules,
    )
