"""autogenerated by genpy from controller/SonarData.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class SonarData(genpy.Message):
  _md5sum = "7934ff36ec557a739a2288dd6df3b8ce"
  _type = "controller/SonarData"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """float64 x_pos
float64 x_neg
float64 y_pos
float64 y_neg
float64 up
float64 down

"""
  __slots__ = ['x_pos','x_neg','y_pos','y_neg','up','down']
  _slot_types = ['float64','float64','float64','float64','float64','float64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       x_pos,x_neg,y_pos,y_neg,up,down

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(SonarData, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.x_pos is None:
        self.x_pos = 0.
      if self.x_neg is None:
        self.x_neg = 0.
      if self.y_pos is None:
        self.y_pos = 0.
      if self.y_neg is None:
        self.y_neg = 0.
      if self.up is None:
        self.up = 0.
      if self.down is None:
        self.down = 0.
    else:
      self.x_pos = 0.
      self.x_neg = 0.
      self.y_pos = 0.
      self.y_neg = 0.
      self.up = 0.
      self.down = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_6d.pack(_x.x_pos, _x.x_neg, _x.y_pos, _x.y_neg, _x.up, _x.down))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 48
      (_x.x_pos, _x.x_neg, _x.y_pos, _x.y_neg, _x.up, _x.down,) = _struct_6d.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_6d.pack(_x.x_pos, _x.x_neg, _x.y_pos, _x.y_neg, _x.up, _x.down))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 48
      (_x.x_pos, _x.x_neg, _x.y_pos, _x.y_neg, _x.up, _x.down,) = _struct_6d.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_6d = struct.Struct("<6d")
