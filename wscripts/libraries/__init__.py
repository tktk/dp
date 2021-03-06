# -*- coding: utf-8 -*-

from . import common
from . import xlib
from . import input
from . import display
from . import window
from . import opengl
from . import audio
from . import file
#from .builder import buildCompositeLibrary

def build( _ctx ):
    sourcesSet = set()
    librariesSet = set()

    common.build(
        _ctx,
        sourcesSet,
        librariesSet,
    )

    input.build(
        _ctx,
        sourcesSet,
        librariesSet,
    )

    xlib.build(
        _ctx,
        sourcesSet,
        librariesSet,
    )

    display.build(
        _ctx,
        sourcesSet,
        librariesSet,
    )

    window.build(
        _ctx,
        sourcesSet,
        librariesSet,
    )

    opengl.build(
        _ctx,
        sourcesSet,
        librariesSet,
    )

    audio.build(
        _ctx,
        sourcesSet,
        librariesSet,
    )

    file.build(
        _ctx,
        sourcesSet,
        librariesSet,
    )

#    buildCompositeLibrary(
#        _ctx,
#        {
#            'dp_setup',
#        },
#        sourcesSet,
#        librariesSet,
#    )
