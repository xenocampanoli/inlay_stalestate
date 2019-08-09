
import json

TopFolder='..'
BoleFolder="%s/bole" % TopFolder
DefaultBoleFSpec="%s/default.json" % BoleFolder
DefaultSoilFSpec="%s/soil.json" % TopFolder

class Bole:

    def __init__(self,boleFSpec=DefaultBoleFSpec):
        self.boleFSpec = boleFSpec

class Soil:

    def __init__(self,soilFSpec=DefaultSoilFSpec):
        self.soilFSpec = soilFSpec

class Mold:

    def __init__(self, boleO, soilO):
        self.boleO = boleO
        self.soilO = soilO
