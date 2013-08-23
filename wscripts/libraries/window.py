# -*- coding: utf-8 -*-

from wscripts import common
from .builder import buildPartialLibrary

def build(
    _ctx,
    _sourcesSet,
    _librariesSet,
):
    sources = {
        'window',
        'windowinfo',
    }

    osSources = {
        'window',
    }

    buildPartialLibrary(
        _ctx,
        _sourcesSet,
        _librariesSet,
        'window',
        sources = sources,
        osSources = osSources,
    )
