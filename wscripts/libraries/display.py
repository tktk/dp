# -*- coding: utf-8 -*-

from wscripts import common
from .builder import buildPartialLibrary

def build(
    _ctx,
    _sourcesSet,
    _librariesSet,
):
    sources = {
        'displaymanager',
        'displaymanagerinfo',
        'displaykey',
    }

    osSources = {
        'displaymanager',
        'displaykey',
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
        sources = sources,
        osSources = osSources,
        libraries = libraries,
    )
