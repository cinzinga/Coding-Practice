#!/usr/bin/env python

"""
A custom sqlmap tamper script that will URL encode only special characters, not words.

By: cinzinga
"""

from urllib import quote
from lib.core.enums import PRIORITY

__priority__ = PRIORITY.LOW


def dependencies():
    pass

def tamper(payload, **kwargs):
	retVal = quote(payload, safe='')
	return retVal
