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
    }

    osSources = {
        'displaymanager',
    }

    buildPartialLibrary(
        _ctx,
        _sourcesSet,
        _librariesSet,
        'display',
        sources = sources,
        osSources = osSources,
    )
