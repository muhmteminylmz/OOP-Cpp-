

import numpy as np

def azel_to_thetaphi(az, el):
 
 cos_theta = np.cos(el) * np.cos(az)
 tan_phi = np.tan(el) / np.sin(az)
 theta = np.arccos(cos_theta)
 phi = np.arctan2(np.tan(el), np.sin(az))
 phi = (phi + 2 * np.pi) % (2 * np.pi)
 
 return theta, phi
 

def thetaphi_to_azel(theta, phi):

 sin_el = np.sin(phi) * np.sin(theta)
 tan_az = np.cos(phi) * np.tan(theta)
 el = np.arcsin(sin_el)
 az = np.arctan(tan_az)
 
 return az, el

def thetaphi_to_uv(theta, phi):
 
 u = np.sin(theta) * np.cos(phi)
 v = np.sin(theta) * np.sin(phi)
 w = np.cos(theta)
 
 return u, v

def azel_to_uv(az, el):

 u = np.cos(el) * np.sin(az)
 v = np.sin(el)
 w = np.cos(az) * np.cos(el)
 return u, v

def uv_to_thetaphi(u, v):
 """ U-V direction cosines to theta-phi coordinates

 Args:
 u (float or np.array): U direction cosine
 v (float or np.array): V direction cosine

:

"""