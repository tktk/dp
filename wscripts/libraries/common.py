# -*- coding: utf-8 -*-

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

    buildPartialLibrary(
        _ctx,
        _sourcesSet,
        _librariesSet,
        'common',
        setupSources = setupSources,
        osSources = osSources,
    )
