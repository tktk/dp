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
        'gamepad',
        'gamepadinfo',
    }

    osSources = {
        'gamepadmanager',
        'gamepadkey',
        'gamepad',
    }

    libraries = set()
    if _ctx.osName == common.LINUX:
        libraries |= {
            'pthread',
            'udev',
        }

    buildPartialLibrary(
        _ctx,
        _sourcesSet,
        _librariesSet,
        'input',
        sources = sources,
        osSources = osSources,
        libraries = libraries,
    )
