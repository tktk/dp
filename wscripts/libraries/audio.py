# -*- coding: utf-8 -*-

from wscripts import common
from .builder import buildPartialLibrary

def build(
    _ctx,
    _sourcesSet,
    _librariesSet,
):
    sources = {
        'speakermanager',
        'speakermanagerinfo',
        'speakerkey',
    }

    osSources = {
        'speakermanager',
        'speakerkey',
    }

    buildPartialLibrary(
        _ctx,
        _sourcesSet,
        _librariesSet,
        'audio',
        sources = sources,
        osSources = osSources,
    )
