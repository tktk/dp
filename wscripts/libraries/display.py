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
            'display_setup',
        }

    sources = {
        'displaymanager',
        'displaymanagerinfo',
        'displaykey',
        'display',
        'displaymodekey',
        'displaymode',
    }

    osSources = {
        'displaymanager',
        'displaykey',
        'display',
        'displaymodekey',
        'displaymode',
    }
    if _ctx.osName == common.LINUX:
        osSources |= {
            'x11',
        }

    libraries = set()
    if _ctx.osName == common.LINUX:
        libraries |= {
            'pthread',
            'X11',
            'Xrandr',
        }

    buildPartialLibrary(
        _ctx,
        _sourcesSet,
        _librariesSet,
        'display',
        setupSources = setupSources,
        sources = sources,
        osSources = osSources,
        libraries = libraries,
    )
