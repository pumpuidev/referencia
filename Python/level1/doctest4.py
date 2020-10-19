#! /usr/bin/env python
# -*- coding: utf-8 -*-

"""

>>> print range(10) # doctest: +NORMALIZE_WHITESPACE
[0,   1,  2,  3,  4,  
5,  6,  7,  8,  9]

>>> print range(10) # doctest: +ELLIPSIS
[0, 1, ..., 8, 9]

>>> print range(10) # doctest: +ELLIPSIS, +NORMALIZE_WHITESPACE
[0,    1, ...,   8,    9]

>>> print range(10) # doctest: +ELLIPSIS
...                 # doctest: +NORMALIZE_WHITESPACE
[0,    1, ...,   8,    9]

>>> print range(10) 
... # doctest: +ELLIPSIS
[0, 1, ..., 8, 9]

>>> r + 43 * 10 # doctest: +IGNORE_EXCEPTION_DETAIL
Traceback (most recent call last):
NameError:
"""

# + ELLIPSIS  ---- "..." olyan, mint a ".*"  a reguláris kifejezéseknél

# python -m doctest -v doctest4.py


