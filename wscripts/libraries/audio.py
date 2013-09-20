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
            'audio_setup',
        }

    sources = {
        'speakermanager',
        'speakermanagerinfo',
        'speakerkey',
    }

    osSources = {
        'speakermanager',
        'speakerkey',
    }
    if _ctx.osName == common.LINUX:
        osSources |= {
            'pulseaudio',
        }

    libraries = set()
    if _ctx.osName == common.LINUX:
        libraries |= {
            'pulse',
        }

    buildPartialLibrary(
        _ctx,
        _sourcesSet,
        _librariesSet,
        'audio',
        setupSources = setupSources,
        sources = sources,
        osSources = osSources,
        libraries = libraries,
    )
