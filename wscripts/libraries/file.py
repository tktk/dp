# -*- coding: utf-8 -*-

from wscripts import common
from .builder import buildPartialLibrary

def build(
    _ctx,
    _sourcesSet,
    _librariesSet,
):
    sources = {
        'filer',
        'filew',
        'filerw',
    }

    osSources = {
        'fileimpl',
        'filer',
        'filew',
        'filerw',
    }

    buildPartialLibrary(
        _ctx,
        _sourcesSet,
        _librariesSet,
        'file',
        sources = sources,
        osSources = osSources,
    )
