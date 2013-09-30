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
            'xlib_setup',
        }

    osSources = set()
    if _ctx.osName == common.LINUX:
        osSources |= {
            'xlib',
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
        'xlib',
        setupSources = setupSources,
        osSources = osSources,
        libraries = libraries,
    )
