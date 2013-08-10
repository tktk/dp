# -*- coding: utf-8 -*-

from wscripts import common
from .builder import buildPartialLibrary

def build(
    _ctx,
    _sourcesSet,
    _librariesSet,
):
    setupSources = {
        'common_setup',
    }

    osSources = {
        'common',
        'stringconverter',
        'args',
    }
    if _ctx.osName == common.LINUX:
        osSources |= {
            'x11',
        }

    libraries = set()
    if _ctx.osName == common.LINUX:
        libraries |= {
            'X11',
        }

    buildPartialLibrary(
        _ctx,
        _sourcesSet,
        _librariesSet,
        'common',
        setupSources = setupSources,
        osSources = osSources,
        libraries = libraries,
    )
