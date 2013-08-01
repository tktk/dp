# -*- coding: utf-8 -*-

from wscripts import common
from .builder import buildPartialLibrary

def build(
    _ctx,
    _sourcesSet,
    _librariesSet,
):
    sources = {
        'gamepadmanager',
        'gamepadmanagerinfo',
        'gamepadkey',
    }

    osSources = {
        'gamepadmanager',
        'gamepadkey',
    }

    buildPartialLibrary(
        _ctx,
        _sourcesSet,
        _librariesSet,
        'input',
        sources = sources,
        osSources = osSources,
    )
