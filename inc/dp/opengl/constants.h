﻿#ifndef DP_OPENGL_CONSTANTS_H
#define DP_OPENGL_CONSTANTS_H

namespace dp {
    enum {
        // Utility
        GL_VENDOR = 0x1f00,
        GL_RENDERER = 0x1f01,
        GL_VERSION = 0x1f02,
        GL_EXTENSIONS = 0x1f03,

        // Data types
        GL_BYTE = 0x1400,
        GL_UNSIGNED_BYTE = 0x1401,
        GL_SHORT = 0x1402,
        GL_UNSIGNED_SHORT = 0x1403,
        GL_INT = 0x1404,
        GL_UNSIGNED_INT = 0x1405,
        GL_FLOAT = 0x1406,
        GL_2_BYTES = 0x1407,
        GL_3_BYTES = 0x1408,
        GL_4_BYTES = 0x1409,
        GL_DOUBLE = 0x140a, // >=GL1.1

        // Simple values
        GL_FALSE = 0,
        GL_TRUE = 1,
        GL_ZERO = 0,
        GL_ONE = 1,
        GL_NONE = 0,

        // Errors
        GL_NO_ERROR = 0,
        GL_INVALID_ENUM = 0x0500,
        GL_INVALID_VALUE = 0x0501,
        GL_INVALID_OPERATION = 0x0502,
        GL_STACK_OVERFLOW = 0x0503,
        GL_STACK_UNDERFLOW = 0x0504,
        GL_OUT_OF_MEMORY = 0x0505,

        // Primitives
        GL_POINTS = 0x0000,
        GL_LINES = 0x0001,
        GL_LINE_LOOP = 0x0002,
        GL_LINE_STRIP = 0x0003,
        GL_TRIANGLES = 0x0004,
        GL_TRIANGLE_STRIP = 0x0005,
        GL_TRIANGLE_FAN = 0x0006,
        GL_QUADS = 0x0007,
        GL_QUAD_STRIP = 0x0008,
        GL_POLYGON = 0x0009,

        // Matrix
        GL_MATRIX_MODE = 0x0ba0,
        GL_NORMALIZE = 0x0ba1,
        GL_VIEWPORT = 0x0ba2,
        GL_MAX_MODELVIEW_STACK_DEPTH = 0x0d36,
        GL_MODELVIEW_STACK_DEPTH = 0x0ba3,
        GL_MAX_PROJECTION_STACK_DEPTH = 0x0d38,
        GL_PROJECTION_STACK_DEPTH = 0x0ba4,
        GL_MAX_TEXTURE_STACK_DEPTH = 0x0d39,
        GL_TEXTURE_STACK_DEPTH = 0x0ba5,
        GL_MODELVIEW_MATRIX = 0x0ba6,
        GL_PROJECTION_MATRIX = 0x0ba7,
        GL_TEXTURE_MATRIX = 0x0ba8,

        // Matrix modes
        GL_MODELVIEW = 0x1700,
        GL_PROJECTION = 0x1701,
        GL_TEXTURE = 0x1702,

        // Texture
        GL_MAX_TEXTURE_SIZE = 0x0d33,
        GL_TEXTURE0 = 0x84c0,

        // Texture coordinate
        GL_S = 0x2000,
        GL_T = 0x2001,
        GL_R = 0x2002,
        GL_Q = 0x2003,
        GL_TEXTURE_GEN_S = 0x0c60,
        GL_TEXTURE_GEN_T = 0x0c61,
        GL_TEXTURE_GEN_R = 0x0c62,
        GL_TEXTURE_GEN_Q = 0x0c63,

        // Texture coordinate generation function or function parameters
        GL_TEXTURE_GEN_MODE = 0x2500,
        GL_OBJECT_PLANE = 0x2501,
        GL_EYE_PLANE = 0x2502,

        // Texture generation parameters
        GL_EYE_LINEAR = 0x2400,
        GL_OBJECT_LINEAR = 0x2401,
        GL_SPHERE_MAP = 0x2402,

        // Texture mapping
        GL_TEXTURE_1D = 0x0de0,
        GL_TEXTURE_2D = 0x0de1,
        GL_PROXY_TEXTURE_1D = 0x8063,   // >=GL1.1
        GL_PROXY_TEXTURE_2D = 0x8064,   // >=GL1.1
        GL_NEAREST = 0x2600,
        GL_LINEAR = 0x2601,
        GL_NEAREST_MIPMAP_NEAREST = 0x2700,
        GL_LINEAR_MIPMAP_NEAREST = 0x2701,
        GL_NEAREST_MIPMAP_LINEAR = 0x2702,
        GL_LINEAR_MIPMAP_LINEAR = 0x2703,
        GL_TEXTURE_MAG_FILTER = 0x2800,
        GL_TEXTURE_MIN_FILTER = 0x2801,
        GL_TEXTURE_WRAP_S = 0x2802,
        GL_TEXTURE_WRAP_T = 0x2803,
        GL_CLAMP = 0x2900,
        GL_REPEAT = 0x2901,
        GL_TEXTURE_WIDTH = 0x1000,
        GL_TEXTURE_HEIGHT = 0x1001,
        GL_TEXTURE_COMPONENTS = 0x1003, // <GL1.1
        GL_TEXTURE_INTERNAL_FORMAT = 0x1003,    // >=GL1.1
        GL_TEXTURE_BORDER_COLOR = 0x1004,
        GL_TEXTURE_BORDER = 0x1005,
        GL_TEXTURE_ENV = 0x2300,
        GL_TEXTURE_ENV_MODE = 0x2200,
        GL_TEXTURE_ENV_COLOR = 0x2201,
        GL_TEXTURE_RED_SIZE = 0x805c,   // >=GL1.1
        GL_TEXTURE_GREEN_SIZE = 0x805d, // >=GL1.1
        GL_TEXTURE_BLUE_SIZE = 0x805e,  // >=GL1.1
        GL_TEXTURE_ALPHA_SIZE = 0x805f, // >=GL1.1
        GL_TEXTURE_LUMINANCE_SIZE = 0x8060, // >=GL1.1
        GL_TEXTURE_INTENSITY_SIZE = 0x8061, // >=GL1.1
        GL_TEXTURE_PRIORITY = 0x8066,   // >=GL1.1
        GL_TEXTURE_RESIDENT = 0x8067,   // >=GL1.1
        GL_TEXTURE_BINDING_1D = 0x8068, // >=GL1.1
        GL_TEXTURE_BINDING_2D = 0x8069, // >=GL1.1
        GL_MODULATE = 0x2100,
        GL_DECAL = 0x2101,

        // Clipping planes
        GL_MAX_CLIP_PLANES = 0x0d32,
        GL_CLIP_PLANE0 = 0x3000,

        // Lighting
        GL_LIGHTING = 0x0b50,
        GL_LIGHT_MODEL_LOCAL_VIEWER = 0x0b51,
        GL_LIGHT_MODEL_TWO_SIDE = 0x0b52,
        GL_LIGHT_MODEL_AMBIENT = 0x0b53,
        GL_SHADE_MODEL = 0x0b54,
        GL_COLOR_MATERIAL_FACE = 0x0b55,
        GL_COLOR_MATERIAL_PARAMETER = 0x0b56,
        GL_COLOR_MATERIAL = 0x0b57,
        GL_MAX_LIGHTS = 0x0d31,
        GL_LIGHT0 = 0x4000,
        GL_AMBIENT = 0x1200,
        GL_DIFFUSE = 0x1201,
        GL_SPECULAR = 0x1202,
        GL_POSITION = 0x1203,
        GL_SPOT_DIRECTION = 0x1204,
        GL_SPOT_EXPONENT = 0x1205,
        GL_SPOT_CUTOFF = 0x1206,
        GL_CONSTANT_ATTENUATION = 0x1207,
        GL_LINEAR_ATTENUATION = 0x1208,
        GL_QUADPATIC_ATTENUATION = 0x1209,
        GL_EMISSION = 0x1600,
        GL_SHININESS = 0x1601,
        GL_AMBIENT_AND_DIFFUSE = 0x1602,
        GL_COLOR_INDEXES = 0x1603,

        // Orientation of front-facing polygons
        GL_CW = 0x0900,
        GL_CCW = 0x0901,

        // Shading technique
        GL_FLAT = 0x1d00,
        GL_SMOOTH = 0x1d01,

        // Points
        GL_POINT_SMOOTH = 0x0b10,
        GL_POINT_SIZE = 0x0b11,
        GL_POINT_SIZE_RANGE = 0x0b12,
        GL_POINT_SIZE_GRANULARITY = 0x0b13,

        // Lines
        GL_LINE_SMOOTH = 0x0b20,
        GL_LINE_WIDTH = 0x0b21,
        GL_LINE_WIDTH_RANGE = 0x0b22,
        GL_LINE_WIDTH_GRANULARITY = 0x0b23,
        GL_LINE_STIPPLE = 0x0b24,
        GL_LINE_STIPPLE_PATTERN = 0x0b25,
        GL_LINE_STIPPLE_REPEAT = 0x0b26,

        // Polygons
        GL_POLYGON_MODE = 0x0b40,
        GL_POLYGON_SMOOTH = 0x0b41,
        GL_POLYGON_STIPPLE = 0x0b42,
        GL_EDGE_FLAG = 0x0b43,
        GL_CULL_FACE = 0x0b44,
        GL_CULL_FACE_MODE = 0x0b45,
        GL_FRONT_FACE = 0x0b46,
        GL_POINT = 0x1b00,
        GL_LINE = 0x1b01,
        GL_FILL = 0x1b02,
        GL_POLYGON_OFFSET_UNITS = 0x2a00,   // >=GL1.1
        GL_POLYGON_OFFSET_POINT = 0x2a01,   // >=GL1.1
        GL_POLYGON_OFFSET_LINE = 0x2a02,    // >=GL1.1
        GL_POLYGON_OFFSET_FILL = 0x8037,    // >=GL1.1
        GL_POLYGON_OFFSET_FACTOR = 0x8038,  // >=GL1.1

        // Pixels
        GL_BITMAP = 0x1a00,
        GL_FRONT_LEFT = 0x0400,
        GL_FRONT_RIGHT = 0x0401,
        GL_BACK_LEFT = 0x0402,
        GL_BACK_RIGHT = 0x0403,
        GL_FRONT = 0x0404,
        GL_BACK = 0x0405,
        GL_LEFT = 0x0406,
        GL_RIGHT = 0x0407,
        GL_FRONT_AND_BACK = 0x0408,
        GL_AUX0 = 0x0409,
        GL_COLOR = 0x1800,
        GL_DEPTH = 0x1801,
        GL_STENCIL = 0x1802,

        // Format of pixel
        GL_COLOR_INDEX = 0x1900,
        GL_STENCIL_INDEX = 0x1901,
        GL_DEPTH_COMPONENT = 0x1902,
        GL_RED = 0x1903,
        GL_GREEN = 0x1904,
        GL_BLUE = 0x1905,
        GL_ALPHA = 0x1906,
        GL_RGB = 0x1907,
        GL_RGBA = 0x1908,
        GL_LUMINANCE = 0x1909,
        GL_LUMINANCE_ALPHA = 0x190a,
        GL_ALPHA4 = 0x803b, // >=GL1.1
        GL_ALPHA8 = 0x803c, // >=GL1.1
        GL_ALPHA12 = 0x803d,    // >=GL1.1
        GL_ALPHA16 = 0x803e,    // >=GL1.1
        GL_LUMINANCE4 = 0x803f, // >=GL1.1
        GL_LUMINANCE8 = 0x8040, // >=GL1.1
        GL_LUMINANCE12 = 0x8041,    // >=GL1.1
        GL_LUMINANCE16 = 0x8042,    // >=GL1.1
        GL_LUMINANCE4_ALPHA4 = 0x8043,  // >=GL1.1
        GL_LUMINANCE6_ALPHA2 = 0x8044,  // >=GL1.1
        GL_LUMINANCE8_ALPHA8 = 0x8045,  // >=GL1.1
        GL_LUMINANCE12_ALPHA4 = 0x8046, // >=GL1.1
        GL_LUMINANCE12_ALPHA12 = 0x8047,    // >=GL1.1
        GL_LUMINANCE16_ALPHA16 = 0x8048,    // >=GL1.1
        GL_INTENSITY = 0x8049,  // >=GL1.1
        GL_INTENSITY4 = 0x804a, // >=GL1.1
        GL_INTENSITY8 = 0x804b, // >=GL1.1
        GL_INTENSITY12 = 0x804c,    // >=GL1.1
        GL_INTENSITY16 = 0x804d,    // >=GL1.1
        GL_R3_G3_B2 = 0x2a10,   // >=GL1.1
        GL_RGB4 = 0x804f,   // >=GL1.1
        GL_RGB5 = 0x8050,   // >=GL1.1
        GL_RGB8 = 0x8051,   // >=GL1.1
        GL_RGB10 = 0x8052,  // >=GL1.1
        GL_RGB12 = 0x8053,  // >=GL1.1
        GL_RGB16 = 0x8054,  // >=GL1.1
        GL_RGBA2 = 0x8055,  // >=GL1.1
        GL_RGBA4 = 0x8056,  // >=GL1.1
        GL_RGB5_A1 = 0x8057,    // >=GL1.1
        GL_RGBA8 = 0x8058,  // >=GL1.1
        GL_RGB10_A2 = 0x8059,   // >=GL1.1
        GL_RGBA12 = 0x805a, // >=GL1.1
        GL_RGBA16 = 0x805b, // >=GL1.1

        // Pixel mode / transfer
        GL_MAP_COLOR = 0x0d10,
        GL_MAP_STENCIL = 0x0d11,
        GL_INDEX_SHIFT = 0x0d12,
        GL_INDEX_OFFSET = 0x0d13,
        GL_RED_SCALE = 0x0d14,
        GL_RED_BIAS = 0x0d15,
        GL_ZOOM_X = 0x0d16,
        GL_ZOOM_Y = 0x0d17,
        GL_GREEN_SCALE = 0x0d18,
        GL_GREEN_BIAS = 0x0d19,
        GL_BLUE_SCALE = 0x0d1a,
        GL_BLUE_BIAS = 0x0d1b,
        GL_ALPHA_SCALE = 0x0d1c,
        GL_ALPHA_BIAS = 0x0d1d,
        GL_DEPTH_SCALE = 0x0d1e,
        GL_DEPTH_BIAS = 0x0d1f,
        GL_PIXEL_MAP_I_TO_I = 0x0c70,
        GL_PIXEL_MAP_S_TO_S = 0x0c71,
        GL_PIXEL_MAP_I_TO_R = 0x0c72,
        GL_PIXEL_MAP_I_TO_G = 0x0c73,
        GL_PIXEL_MAP_I_TO_B = 0x0c74,
        GL_PIXEL_MAP_I_TO_A = 0x0c75,
        GL_PIXEL_MAP_R_TO_R = 0x0c76,
        GL_PIXEL_MAP_G_TO_G = 0x0c77,
        GL_PIXEL_MAP_B_TO_B = 0x0c78,
        GL_PIXEL_MAP_A_TO_A = 0x0c79,
        GL_PIXEL_MAP_I_TO_I_SIZE = 0x0cb0,
        GL_PIXEL_MAP_S_TO_S_SIZE = 0x0cb1,
        GL_PIXEL_MAP_I_TO_R_SIZE = 0x0cb2,
        GL_PIXEL_MAP_I_TO_G_SIZE = 0x0cb3,
        GL_PIXEL_MAP_I_TO_B_SIZE = 0x0cb4,
        GL_PIXEL_MAP_I_TO_A_SIZE = 0x0cb5,
        GL_PIXEL_MAP_R_TO_R_SIZE = 0x0cb6,
        GL_PIXEL_MAP_G_TO_G_SIZE = 0x0cb7,
        GL_PIXEL_MAP_B_TO_B_SIZE = 0x0cb8,
        GL_PIXEL_MAP_A_TO_A_SIZE = 0x0cb9,
        GL_UNPACK_SWAP_BYTES = 0x0cf0,
        GL_UNPACK_LSB_FIRST = 0x0cf1,
        GL_UNPACK_ROW_LENGTH = 0x0cf2,
        GL_UNPACK_SKIP_ROWS = 0x0cf3,
        GL_UNPACK_SKIP_PIXELS = 0x0cf4,
        GL_UNPACK_ALIGNMENT = 0x0cf5,
        GL_PACK_SWAP_BYTES = 0x0d00,
        GL_PACK_LSB_FIRST = 0x0d01,
        GL_PACK_ROW_LENGTH = 0x0d02,
        GL_PACK_SKIP_ROWS = 0x0d03,
        GL_PACK_SKIP_PIXELS = 0x0d04,
        GL_PACK_ALIGNMENT = 0x0d05,
        GL_COEFF = 0x0a00,
        GL_ORDER = 0x0a01,
        GL_DOMAIN = 0x0a02,

        // Fog
        GL_FOG = 0x0b60,
        GL_FOG_INDEX = 0x0b61,
        GL_FOG_DENSITY = 0x0b62,
        GL_FOG_START = 0x0b63,
        GL_FOG_END = 0x0b64,
        GL_FOG_MODE = 0x0b65,
        GL_FOG_COLOR = 0x0b66,
        GL_EXP = 0x0800,
        GL_EXP2 = 0x0801,

        // Comparison function
        GL_NEVER = 0x0200,
        GL_LESS = 0x0201,
        GL_EQUAL = 0x0202,
        GL_LEQUAL = 0x0203,
        GL_GREATER = 0x0204,
        GL_NOTEQUAL = 0x0205,
        GL_GEQUAL = 0x0206,
        GL_ALWAYS = 0x0207,

        // Scissor test
        GL_SCISSOR_BOX = 0x0c10,
        GL_SCISSOR_TEST = 0x0c11,

        // Alpha test
        GL_ALPHA_TEST = 0x0bc0,
        GL_ALPHA_TEST_FUNC = 0x0bc1,
        GL_ALPHA_TEST_REF = 0x0bc2,

        // Stencil test
        GL_STENCIL_TEST = 0x0b90,
        GL_STENCIL_FUNC = 0x0b92,
        GL_STENCIL_VALUE_MASK = 0x0b93,
        GL_STENCIL_FAIL = 0x0b94,
        GL_STENCIL_PASS_DEPTH_FAIL = 0x0b95,
        GL_STENCIL_PASS_DEPTH_PASS = 0x0b96,
        GL_STENCIL_REF = 0x0b97,
        GL_KEEP = 0x1e00,
        GL_REPLACE = 0x1e01,
        GL_INCR = 0x1e02,
        GL_DECR = 0x1e03,

        // Depth test
        GL_DEPTH_RANGE = 0x0b70,
        GL_DEPTH_TEST = 0x0b71,
        GL_DEPTH_FUNC = 0x0b74,

        // Blending
        GL_BLEND_DST = 0x0be0,
        GL_BLEND_SRC = 0x0be1,
        GL_BLEND = 0x0be2,
        GL_SRC_COLOR = 0x0300,
        GL_ONE_MINUS_SRC_COLOR = 0x0301,
        GL_SRC_ALPHA = 0x0302,
        GL_ONE_MINUS_SRC_ALPHA = 0x0303,
        GL_DST_ALPHA = 0x0304,
        GL_ONE_MINUS_DST_ALPHA = 0x0305,
        GL_DST_COLOR = 0x0306,
        GL_ONE_MINUS_DST_COLOR = 0x0307,
        GL_SRC_ALPHA_SATURATE = 0x0308,

        // Dithering
        GL_DITHER = 0x0bd0,

        // Logical Operation
        GL_LOGIC_OP_MODE = 0x0bf0,
        GL_LOGIC_OP = 0x0bf1,   // <GL1.1
        GL_INDEX_LOGIC_OP = 0x0bf1, // >=GL1.1
        GL_COLOR_LOGIC_OP = 0x0bf2, // >=GL1.1
        GL_CLEAR = 0x1500,
        GL_AND = 0x1501,
        GL_AND_REVERSE = 0x1502,
        GL_COPY = 0x1503,
        GL_AND_INVERTED = 0x1504,
        GL_NOOP = 0x1505,
        GL_XOR = 0x1506,
        GL_OR = 0x1507,
        GL_NOR = 0x1508,
        GL_EQUIV = 0x1509,
        GL_INVERT = 0x150a,
        GL_OR_REVERSE = 0x150b,
        GL_COPY_INVERTED = 0x150c,
        GL_OR_INVERTED = 0x150d,
        GL_NAND = 0x150e,
        GL_SET = 0x150f,

        // Accumulation buffer
        GL_ACCUM = 0x0100,
        GL_LOAD = 0x0101,
        GL_RETURN = 0x0102,
        GL_MULT = 0x0103,
        GL_ADD = 0x0104,

        // Evaluators
        GL_MAX_EVAL_ORDER = 0x0d30,
        GL_AUTO_NORMAL = 0x0d80,
        GL_MAP1_COLOR_4 = 0x0d90,
        GL_MAP1_INDEX = 0x0d91,
        GL_MAP1_NORMAL = 0x0d92,
        GL_MAP1_TEXTURE_COORD_1 = 0x0d93,
        GL_MAP1_TEXTURE_COORD_2 = 0x0d94,
        GL_MAP1_TEXTURE_COORD_3 = 0x0d95,
        GL_MAP1_TEXTURE_COORD_4 = 0x0d96,
        GL_MAP1_VERTEX_3 = 0x0d97,
        GL_MAP1_VERTEX_4 = 0x0d98,
        GL_MAP2_COLOR_4 = 0x0db0,
        GL_MAP2_INDEX = 0x0db1,
        GL_MAP2_NORMAL = 0x0db2,
        GL_MAP2_TEXTURE_COORD_1 = 0x0db3,
        GL_MAP2_TEXTURE_COORD_2 = 0x0db4,
        GL_MAP2_TEXTURE_COORD_3 = 0x0db5,
        GL_MAP2_TEXTURE_COORD_4 = 0x0db6,
        GL_MAP2_VERTEX_3 = 0x0db7,
        GL_MAP2_VERTEX_4 = 0x0db8,
        GL_MAP1_GRID_DOMAIN = 0x0dd0,
        GL_MAP1_GRID_SEGMENPS = 0x0dd1,
        GL_MAP2_GRID_DOMAIN = 0x0dd2,
        GL_MAP2_GRID_SEGMENPS = 0x0dd3,

        // Render mode
        GL_RENDER = 0x1c00,
        GL_FEEDBACK = 0x1c01,
        GL_SELECT = 0x1c02,

        // Feedback
        GL_2D = 0x0600,
        GL_3D = 0x0601,
        GL_3D_COLOR = 0x0602,
        GL_3D_COLOR_TEXTURE = 0x0603,
        GL_4D_COLOR_TEXTURE = 0x0604,

        // Feedback Token
        GL_PASS_THROUGH_TOKEN = 0x0700,
        GL_POINT_TOKEN = 0x0701,
        GL_LINE_TOKEN = 0x0702,
        GL_POLYGON_TOKEN = 0x0703,
        GL_BITMAP_TOKEN = 0x0704,
        GL_DRAW_PIXEL_TOKEN = 0x0705,
        GL_COPY_PIXEL_TOKEN = 0x0706,
        GL_LINE_RESET_TOKEN = 0x0707,

        // Display Lists
        GL_COMPILE = 0x1300,
        GL_COMPILE_AND_EXECUTE = 0x1301,
        GL_LIST_BASE = 0x0b32,
        GL_LIST_INDEX = 0x0b33,
        GL_LIST_MODE = 0x0b30,

        // Hints
        GL_PERSPECTIVE_CORRECTION_HINT = 0x0c50,
        GL_POINT_SMOOTH_HINT = 0x0c51,
        GL_LINE_SMOOTH_HINT = 0x0c52,
        GL_POLYGON_SMOOTH_HINT = 0x0c53,
        GL_FOG_HINT = 0x0c54,
        GL_DONT_CARE = 0x1100,
        GL_FASTEST = 0x1101,
        GL_NICEST = 0x1102,

        // Attribute groups
        GL_CURRENT_BIT = 0x00000001,
        GL_POINT_BIT = 0x00000002,
        GL_LINE_BIT = 0x00000004,
        GL_POLYGON_BIT = 0x00000008,
        GL_POLYGON_STIPPLE_BIT = 0x00000010,
        GL_PIXEL_MODE_BIT = 0x00000020,
        GL_LIGHTING_BIT = 0x00000040,
        GL_FOG_BIT = 0x00000080,
        GL_DEPTH_BUFFER_BIT = 0x00000100,
        GL_ACCUM_BUFFER_BIT = 0x00000200,
        GL_STENCIL_BUFFER_BIT = 0x00000400,
        GL_VIEWPORT_BIT = 0x00000800,
        GL_TRANSFORM_BIT = 0x00001000,
        GL_ENABLE_BIT = 0x00002000,
        GL_COLOR_BUFFER_BIT = 0x00004000,
        GL_HINT_BIT = 0x00008000,
        GL_EVAL_BIT = 0x00010000,
        GL_LIST_BIT = 0x00020000,
        GL_TEXTURE_BIT = 0x00040000,
        GL_SCISSOR_BIT = 0x00080000,
        GL_ALL_ATTRIB_BITS = 0x000fffff,
        GL_CLIENT_PIXEL_STORE_BIT = 0x00000001, // >=GL1.1
        GL_CLIENT_VERTEX_ARRAY_BIT = 0x00000002,    // >=GL1.1
        GL_ALL_CLIENTL_ATTRIB_BITS = 0xffffffff,    // >=GL1.1

        // Buffer
        GL_AUX_BUFFERS = 0x0c00,
        GL_DRAW_BUFFER = 0x0c01,
        GL_READ_BUFFER = 0x0c02,

        // Bits
        GL_SUBPIXEL_BITS = 0x0d50,
        GL_INDEX_BITS = 0x0d51,
        GL_RED_BITS = 0x0d52,
        GL_GREEN_BITS = 0x0d53,
        GL_BLUE_BITS = 0x0d54,
        GL_ALPHA_BITS = 0x0d55,
        GL_DEPTH_BITS = 0x0d56,
        GL_STENCIL_BITS = 0x0d57,
        GL_ACCUM_RED_BITS = 0x0d58,
        GL_ACCUM_GREEN_BITS = 0x0d59,
        GL_ACCUM_BLUE_BITS = 0x0d5a,
        GL_ACCUM_ALPHA_BITS = 0x0d5b,

        // Gets
        GL_CURRENT_COLOR = 0x0b00,
        GL_CURRENT_INDEX = 0x0b01,
        GL_CURRENT_NORMAL = 0x0b02,
        GL_CURRENT_TEXTURE_COORDS = 0x0b03,
        GL_CURRENT_RASTER_COLOR = 0x0b04,
        GL_CURRENT_RASTER_INDEX = 0x0b05,
        GL_CURRENT_RASTER_TEXTURE_COORDS = 0x0b06,
        GL_CURRENT_RASTER_POSITION = 0x0b07,
        GL_CURRENT_RASTER_POSITION_VALID = 0x0b08,
        GL_CURRENT_RASTER_DISTANCE = 0x0b09,
        GL_INDEX_CLEAR_VALUE = 0x0c20,
        GL_INDEX_WRITEMASK = 0x0c21,
        GL_COLOR_CLEAR_VALUE = 0x0c22,
        GL_COLOR_WRITEMASK = 0x0c23,
        GL_STENCIL_CLEAR_VALUE = 0x0b91,
        GL_STENCIL_WRITEMASK = 0x0b98,
        GL_DEPTH_CLEAR_VALUE = 0x0b73,
        GL_DEPTH_WRITEMASK = 0x0b72,
        GL_ACCUM_CLEAR_VALUE = 0x0b80,
        GL_MAX_LIST_NESTING = 0x0b31,
        GL_MAX_EVAL_OREDR = 0x0d30,
        GL_MAX_PIXEL_MAP_TABLE = 0x0d34,
        GL_MAX_ATTRIB_STACK_DEPTH = 0x0d35,
        GL_MAX_NAME_STACK_DEPTH = 0x0d37,
        GL_MAX_VIEWPORT_DIMS = 0x0d3a,
        GL_MAX_CLIENT_ATTRIB_STACK_DEPTH = 0x0d3b,  // >=GL1.1
        GL_INDEX_MODE = 0x0c30,
        GL_RGBA_MODE = 0x0c31,
        GL_DOUBLEBUFFER = 0x0c32,
        GL_STEREO = 0x0c33,
        GL_ATTRIB_STACK_DEPTH = 0x0bb0,
        GL_CLIENT_ATTRIB_STACK_DEPTH = 0x0bb1,  // >=GL1.1
        GL_NAME_STACK_DEPTH = 0x0d70,
        GL_RENDER_MODE = 0x0c40,

        // Vertex arrays
        GL_VERTEX_ARRAY = 0x8074,   // >=GL1.1
        GL_VERTEX_ARRAY_SIZE = 0x807a,  // >=GL1.1
        GL_VERTEX_ARRAY_TYPE = 0x807b,  // >=GL1.1
        GL_VERTEX_ARRAY_STRIDE = 0x807c,    // >=GL1.1
        GL_VERTEX_ARRAY_POINTER = 0x808e,   // >=GL1.1
        GL_NORMAL_ARRAY = 0x8075,   // >=GL1.1
        GL_NORMAL_ARRAY_TYPE = 0x807e,  // >=GL1.1
        GL_NORMAL_ARRAY_STRIDE = 0x807f,    // >=GL1.1
        GL_NORMAL_ARRAY_POINTER = 0x808f,   // >=GL1.1
        GL_COLOR_ARRAY = 0x8076,    // >=GL1.1
        GL_COLOR_ARRAY_SIZE = 0x8081,   // >=GL1.1
        GL_COLOR_ARRAY_TYPE = 0x8082,   // >=GL1.1
        GL_COLOR_ARRAY_STRIDE = 0x8083, // >=GL1.1
        GL_COLOR_ARRAY_POINTER = 0x8090,    // >=GL1.1
        GL_INDEX_ARRAY = 0x8077,    // >=GL1.1
        GL_INDEX_ARRAY_TYPE = 0x8085,   // >=GL1.1
        GL_INDEX_ARRAY_STRIDE = 0x8086, // >=GL1.1
        GL_INDEX_ARRAY_POINTER = 0x8091,    // >=GL1.1
        GL_TEXTURE_COORD_ARRAY = 0x8078,    // >=GL1.1
        GL_TEXTURE_COORD_ARRAY_SIZE = 0x8088,   // >=GL1.1
        GL_TEXTURE_COORD_ARRAY_TYPE = 0x8089,   // >=GL1.1
        GL_TEXTURE_COORD_ARRAY_STRIDE = 0x808a, // >=GL1.1
        GL_TEXTURE_COORD_ARRAY_POINTER = 0x8092,    // >=GL1.1
        GL_EDGE_FLAG_ARRAY = 0x8079,    // >=GL1.1
        GL_EDGE_FLAG_ARRAY_STRIDE = 0x808c, // >=GL1.1
        GL_EDGE_FLAG_ARRAY_POINTER = 0x8093,    // >=GL1.1
        GL_SELECTION_BUFFER_POINTER = 0x0df3,   // >=GL1.1
        GL_SELECTION_BUFFER_SIZE = 0x0df4,  // >=GL1.1
        GL_FEEDBACK_BUFFER_POINTER = 0x0df0,    // >=GL1.1
        GL_FEEDBACK_BUFFER_SIZE = 0x0df1,   // >=GL1.1
        GL_FEEDBACK_BUFFER_TYPE = 0x0df2,   // >=GL1.1
        GL_V2F = 0x2a20,    // >=GL1.1
        GL_V3F = 0x2a21,    // >=GL1.1
        GL_C4UB_V2F = 0x2a22,   // >=GL1.1
        GL_C4UB_V3F = 0x2a23,   // >=GL1.1
        GL_C3F_V3F = 0x2a24,    // >=GL1.1
        GL_N3F_V3F = 0x2a25,    // >=GL1.1
        GL_C4F_N3F_V3F = 0x2a26,    // >=GL1.1
        GL_T2F_V3F = 0x2a27,    // >=GL1.1
        GL_T4F_V4F = 0x2a28,    // >=GL1.1
        GL_T2F_C4UB_V3F = 0x2a29,   // >=GL1.1
        GL_T2F_C3F_V3F = 0x2a2a,    // >=GL1.1
        GL_T2F_N3F_V3F = 0x2a2b,    // >=GL1.1
        GL_T2F_C4F_N3F_V3F = 0x2a2c,    // >=GL1.1
        GL_T4F_C4F_N3F_V4F = 0x2a2d,    // >=GL1.1
    };
}

#endif  // DP_OPENGL_CONSTANTS_H
