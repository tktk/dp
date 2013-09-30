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
        'stringconverter',
        'args',
    }

    buildPartialLibrary(
        _ctx,
        _sourcesSet,
        _librariesSet,
        'common',
        setupSources = setupSources,
        osSources = osSources,
    )
