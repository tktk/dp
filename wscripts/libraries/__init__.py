# -*- coding: utf-8 -*-

from . import common
from . import input
from . import display
from . import window
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

#    buildCompositeLibrary(
#        _ctx,
#        {
#            'dp_setup',
#        },
#        sourcesSet,
#        librariesSet,
#    )
