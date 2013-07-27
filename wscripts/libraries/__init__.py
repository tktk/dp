# -*- coding: utf-8 -*-

from . import input
#from .builder import buildCompositeLibrary

def build( _ctx ):
    sourcesSet = set()
    librariesSet = set()

    input.build(
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
