#! /usr/bin/env python
# -*- coding: utf-8 -*-

import os, re


class Search :
    def search(self, name, path) :
        infos = []
        for root, dirs, files in os.walk(path): 
            for file in files :
                if re.match(".*\.py", file) :
                   full = os.path.join(root, file) 
                   sig, doc = self.getInfo(name, full) 
                   if sig : infos.append((full, sig, doc))
        return infos
     
    def getInfo(self, name, file) : 
         "Dummy getInfo"
         return ("","") 
