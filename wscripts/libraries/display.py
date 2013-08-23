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

    libraries = set()
    if _ctx.osName == common.LINUX:
        libraries |= {
            'pthread',
            'Xrandr',
        }

    useModules = set()
    if _ctx.osName == common.LINUX:
        useModules |= {
            'common',
        }

    buildPartialLibrary(
        _ctx,
        _sourcesSet,
        _librariesSet,
        'display',
        sources = sources,
        osSources = osSources,
        libraries = libraries,
        useModules = useModules,
    )
