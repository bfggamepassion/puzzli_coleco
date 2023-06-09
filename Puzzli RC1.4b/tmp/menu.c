
#include <coleco.h>

const byte NAMERLEMENU[] = {
  0x9F, 0xB3, 0x89, 0x85, 0x02, 0xC6, 0x20, 0xC6, 0x92, 0x80, 0x85, 0x85, 0x14, 0xCA, 0xCB,
  0x85, 0x85, 0xC6, 0x20, 0xC6, 0x20, 0x20, 0x53, 0x54, 0x41, 0x52, 0x54, 0x20, 0x47, 0x41, 0x4D,
  0x45, 0x20, 0x20, 0x84, 0x80, 0x01, 0xCA, 0xCB, 0x87, 0x85, 0x02, 0xC6, 0x20, 0xC6, 0x92, 0x80,
  0x86, 0x85, 0x07, 0xC9, 0x85, 0x85, 0xC6, 0x20, 0xC6, 0x88, 0x90, 0x90, 0x80, 0x82, 0x85, 0x01,
  0xCA, 0xCB, 0x84, 0x85, 0x0D, 0xC6, 0x20, 0xC6, 0x89, 0x91, 0x49, 0x46, 0x46, 0x49, 0x43, 0x55,
  0x4C, 0x54, 0x59, 0x87, 0x80, 0x89, 0x85, 0x02, 0xC6, 0x20, 0xC6, 0x92, 0x80, 0x89, 0x85, 0x0A,
  0xC6, 0x20, 0xC6, 0x20, 0x20, 0x45, 0x41, 0x53, 0x59, 0x20, 0x20, 0x8A, 0x80, 0x82, 0x85, 0x03,
  0xB6, 0xBE, 0xBB, 0xC3, 0x82, 0x85, 0x0F, 0xC6, 0x20, 0xC6, 0x20, 0x20, 0x4E, 0x4F, 0x52, 0x4D,
  0x41, 0x4C, 0x20, 0x20, 0x80, 0x80, 0x20, 0x85, 0x80, 0x82, 0x85, 0x11, 0xB7, 0xBF, 0xBC, 0xC4,
  0x85, 0x85, 0xCC, 0xC6, 0x20, 0xC6, 0x20, 0x20, 0x48, 0x41, 0x52, 0x44, 0x20, 0x20, 0x8A, 0x80,
  0x82, 0x85, 0x13, 0xB7, 0xB5, 0xBD, 0xC5, 0x85, 0x85, 0xCD, 0xC6, 0x20, 0xC6, 0x20, 0x20, 0x54,
  0x52, 0x41, 0x49, 0x4E, 0x49, 0x4E, 0x47, 0x83, 0x20, 0x84, 0x80, 0x89, 0x98, 0x02, 0xC6, 0x20,
  0xC6, 0x92, 0x80, 0x89, 0x98, 0x04, 0xC6, 0x20, 0xC6, 0x82, 0x8A, 0x85, 0x80, 0x01, 0x84, 0x8C,
  0x88, 0x80, 0x89, 0x92, 0x0F, 0xC6, 0x20, 0xC6, 0x83, 0x8B, 0x4F, 0x4E, 0x54, 0x52, 0x4F, 0x4C,
  0x80, 0x8D, 0x59, 0x50, 0x45, 0x88, 0x80, 0x00, 0xC8, 0x84, 0x80, 0x03, 0xCF, 0xC6, 0x20, 0xC6,
  0x8C, 0x80, 0x00, 0x20, 0x85, 0x80, 0x02, 0xCF, 0x80, 0xC8, 0x82, 0x80, 0x28, 0xCE, 0x80, 0x80,
  0xC6, 0x20, 0xC6, 0x20, 0x80, 0x54, 0x59, 0x50, 0x45, 0x31, 0x40, 0x42, 0x31, 0x2D, 0x53, 0x57,
  0x49, 0x54, 0x43, 0x48, 0x20, 0x20, 0xCE, 0xCF, 0x80, 0xAC, 0xA0, 0xA8, 0xB0, 0xB8, 0x80, 0xCE,
  0xC6, 0x20, 0xC6, 0x80, 0x80, 0x20, 0x84, 0x80, 0x06, 0x42, 0x32, 0x2D, 0x44, 0x52, 0x4F, 0x50,
  0x83, 0x20, 0x81, 0x80, 0x0D, 0xCF, 0x99, 0xA1, 0xA9, 0xB1, 0xB9, 0xC1, 0x80, 0xC6, 0x20, 0xC6,
  0x80, 0x80, 0x20, 0x8F, 0x80, 0x1B, 0xCF, 0x9D, 0x80, 0x9A, 0xA2, 0xAA, 0xB2, 0xBA, 0xC2, 0xCF,
  0xC6, 0x20, 0xC6, 0x20, 0x80, 0x54, 0x59, 0x50, 0x45, 0x32, 0x40, 0x42, 0x31, 0x2D, 0x44, 0x52,
  0x4F, 0x50, 0x83, 0x40, 0x0F, 0xAD, 0xA5, 0x93, 0x9B, 0xA3, 0xAB, 0x81, 0x81, 0x9D, 0x81, 0xC6,
  0x20, 0xC6, 0x80, 0x80, 0x20, 0x84, 0x80, 0x1A, 0x42, 0x32, 0x2D, 0x53, 0x57, 0x49, 0x54, 0x43,
  0x48, 0x40, 0x40, 0xAE, 0x81, 0x94, 0x9C, 0xA4, 0x81, 0x81, 0x95, 0xA5, 0x81, 0xC6, 0x20, 0xC6,
  0x80, 0x80, 0x20, 0x84, 0x80, 0x00, 0x40, 0x89, 0x80, 0x01, 0xAF, 0xAD, 0x82, 0x81, 0x1C, 0x86,
  0x8E, 0x96, 0x9E, 0xA6, 0xC6, 0x20, 0xC6, 0x20, 0x80, 0x54, 0x59, 0x50, 0x45, 0x33, 0x40, 0x42,
  0x31, 0x2D, 0x53, 0x57, 0x49, 0x54, 0x43, 0x48, 0x40, 0x40, 0x81, 0xAE, 0x82, 0x81, 0x07, 0x87,
  0x8F, 0x97, 0x9F, 0xA7, 0xC6, 0x20, 0xC6, 0x87, 0x80, 0x06, 0x44, 0x57, 0x2D, 0x44, 0x52, 0x4F,
  0x50, 0x83, 0x40, 0x01, 0x81, 0xAF, 0x87, 0x81, 0x02, 0xC6, 0x20, 0xC6, 0x92, 0x80, 0xFF};

const byte PATTERNRLEMENU[] = {
  0xFE, 0x00, 0xFE, 0x00, 0x8B, 0x00, 0x04, 0x0C, 0x18, 0x30, 0x00, 0x60, 0x82, 0x00, 0x81,
  0x66, 0x85, 0x00, 0x21, 0x66, 0xFF, 0x66, 0xFF, 0x66, 0x00, 0x18, 0x3E, 0x60, 0x3C, 0x06, 0x7C,
  0x18, 0x00, 0xFF, 0x81, 0xB9, 0xA5, 0xB9, 0xA5, 0x81, 0xFF, 0x3C, 0x66, 0x3C, 0x38, 0x67, 0x66,
  0x3F, 0x80, 0x00, 0x00, 0x18, 0x30, 0x85, 0x00, 0x00, 0x18, 0x82, 0x30, 0x00, 0x18, 0x82, 0x00,
  0x00, 0x18, 0x82, 0x0C, 0x00, 0x18, 0x82, 0x00, 0x04, 0x5A, 0x3C, 0x7E, 0x3C, 0x5A, 0x82, 0x00,
  0x81, 0x18, 0x02, 0x7E, 0x18, 0x18, 0x85, 0x00, 0x01, 0x18, 0x30, 0x84, 0x00, 0x00, 0x7E, 0x88,
  0x00, 0x00, 0x18, 0x82, 0x00, 0x04, 0x0C, 0x18, 0x30, 0x60, 0xC0, 0x82, 0x00, 0x04, 0x7C, 0xCE,
  0xD6, 0xE6, 0x7C, 0x82, 0x00, 0x04, 0x18, 0x38, 0x18, 0x18, 0x7E, 0x82, 0x00, 0x04, 0x7C, 0x06,
  0x7E, 0x60, 0x7E, 0x82, 0x00, 0x04, 0x7C, 0x06, 0x7C, 0x06, 0x7C, 0x82, 0x00, 0x81, 0xCC, 0x02,
  0xFE, 0x0C, 0x0C, 0x82, 0x00, 0x04, 0x7E, 0x60, 0x7C, 0x06, 0x7C, 0x82, 0x00, 0x04, 0x3E, 0x60,
  0x7C, 0x66, 0x3C, 0x82, 0x00, 0x04, 0xFE, 0x06, 0x0C, 0x18, 0x30, 0x82, 0x00, 0x04, 0x3C, 0x66,
  0x3C, 0x66, 0x3C, 0x82, 0x00, 0x04, 0x3C, 0x66, 0x3C, 0x06, 0x7C, 0x83, 0x00, 0x02, 0x18, 0x00,
  0x18, 0x84, 0x00, 0x0A, 0x18, 0x00, 0x18, 0x30, 0x0E, 0x18, 0x30, 0x60, 0x30, 0x18, 0x0E, 0x84,
  0x00, 0x0A, 0x7E, 0x00, 0x7E, 0x00, 0x00, 0x18, 0x0C, 0x06, 0x0C, 0x18, 0x70, 0x83, 0x00, 0x04,
  0x38, 0x6C, 0x08, 0x00, 0x18, 0x8A, 0x00, 0x04, 0x7C, 0xC6, 0xFE, 0xC6, 0xC6, 0x82, 0x00, 0x04,
  0xFC, 0xC6, 0xFC, 0xC6, 0xFC, 0x82, 0x00, 0x04, 0x7C, 0xC6, 0xC0, 0xC6, 0x7C, 0x82, 0x00, 0x00,
  0xFC, 0x82, 0xC6, 0x00, 0xFC, 0x82, 0x00, 0x04, 0xFE, 0xC0, 0xFE, 0xC0, 0xFE, 0x82, 0x00, 0x04,
  0xFE, 0xC0, 0xFE, 0xC0, 0xC0, 0x82, 0x00, 0x04, 0x7E, 0xC0, 0xDC, 0xC6, 0x7C, 0x82, 0x00, 0x81,
  0xC6, 0x02, 0xFE, 0xC6, 0xC6, 0x82, 0x00, 0x00, 0xFC, 0x82, 0x30, 0x00, 0xFC, 0x82, 0x00, 0x04,
  0xFE, 0x06, 0x06, 0xC6, 0x7C, 0x82, 0x00, 0x04, 0xC6, 0xCC, 0xF8, 0xCC, 0xC6, 0x82, 0x00, 0x83,
  0xC0, 0x00, 0xFE, 0x82, 0x00, 0x04, 0xC6, 0xEE, 0xFE, 0xD6, 0xC6, 0x82, 0x00, 0x04, 0xC6, 0xE6,
  0xFE, 0xCE, 0xC6, 0x82, 0x00, 0x00, 0x7C, 0x82, 0xC6, 0x00, 0x7C, 0x82, 0x00, 0x04, 0xFC, 0xC6,
  0xFC, 0xC0, 0xC0, 0x82, 0x00, 0x04, 0x7C, 0xC6, 0xC6, 0xCC, 0x76, 0x82, 0x00, 0x04, 0xFC, 0xC6,
  0xFC, 0xCC, 0xC6, 0x82, 0x00, 0x04, 0x7E, 0xC0, 0x7C, 0x06, 0xFC, 0x82, 0x00, 0x00, 0xFC, 0x83,
  0x30, 0x82, 0x00, 0x83, 0xC6, 0x00, 0x7C, 0x82, 0x00, 0x82, 0xC6, 0x01, 0x6C, 0x38, 0x82, 0x00,
  0x04, 0xC6, 0xD6, 0xFE, 0xEE, 0xC6, 0x82, 0x00, 0x04, 0xC6, 0x6C, 0x38, 0x6C, 0xC6, 0x82, 0x00,
  0x81, 0xC6, 0x02, 0x7E, 0x06, 0xFC, 0x82, 0x00, 0x06, 0xFC, 0x18, 0x30, 0x60, 0xFC, 0x00, 0x3C,
  0x84, 0x30, 0x0A, 0x3C, 0x00, 0x00, 0x60, 0x30, 0x18, 0x0C, 0x06, 0x03, 0x00, 0x3C, 0x84, 0x0C,
  0x04, 0x3C, 0x00, 0x18, 0x3C, 0x7E, 0x83, 0x18, 0x89, 0x00, 0x01, 0x30, 0x10, 0x85, 0x00, 0x09,
  0x3E, 0x03, 0x3F, 0x63, 0x63, 0x3F, 0x00, 0x60, 0x60, 0x7C, 0x82, 0x66, 0x03, 0x7C, 0x00, 0x00,
  0x3E, 0x83, 0x60, 0x04, 0x3E, 0x00, 0x06, 0x06, 0x3E, 0x82, 0x66, 0x0D, 0x3E, 0x00, 0x00, 0x3C,
  0x66, 0x66, 0x7C, 0x60, 0x3E, 0x00, 0x1C, 0x30, 0x30, 0x7C, 0x82, 0x30, 0x81, 0x00, 0x09, 0x3F,
  0x63, 0x63, 0x3E, 0x01, 0x7E, 0x00, 0x60, 0x60, 0x7E, 0x83, 0x63, 0x02, 0x00, 0x18, 0x00, 0x84,
  0x18, 0x11, 0x00, 0x03, 0x00, 0x03, 0x03, 0x63, 0x63, 0x3E, 0x00, 0x60, 0x66, 0x6C, 0x78, 0x78,
  0x6C, 0x66, 0x00, 0x38, 0x84, 0x18, 0x03, 0x1C, 0x00, 0x00, 0x3E, 0x84, 0x6B, 0x81, 0x00, 0x01,
  0x7C, 0x66, 0x83, 0x63, 0x81, 0x00, 0x00, 0x3E, 0x83, 0x63, 0x03, 0x3E, 0x00, 0x00, 0x7E, 0x82,
  0x63, 0x04, 0x7E, 0x60, 0x00, 0x00, 0x3F, 0x82, 0x63, 0x05, 0x3F, 0x03, 0x00, 0x00, 0x3E, 0x63,
  0x83, 0x60, 0x81, 0x00, 0x09, 0x3F, 0x60, 0x3E, 0x03, 0x03, 0x7E, 0x00, 0x18, 0x18, 0x7F, 0x82,
  0x18, 0x02, 0x0F, 0x00, 0x00, 0x84, 0x63, 0x02, 0x3F, 0x00, 0x00, 0x83, 0x63, 0x13, 0x36, 0x1C,
  0x00, 0x00, 0x63, 0x63, 0x6B, 0x7F, 0x77, 0x63, 0x00, 0x00, 0x63, 0x36, 0x1C, 0x1C, 0x36, 0x63,
  0x00, 0x00, 0x82, 0x63, 0x13, 0x3F, 0x03, 0x7E, 0x00, 0x00, 0x7F, 0x06, 0x0C, 0x18, 0x30, 0x7F,
  0x00, 0x0C, 0x10, 0x10, 0x60, 0x10, 0x10, 0x0C, 0x00, 0x86, 0x08, 0x07, 0x00, 0x30, 0x08, 0x08,
  0x06, 0x08, 0x08, 0x30, 0x83, 0x00, 0x01, 0x32, 0x4C, 0x82, 0x00, 0x06, 0x55, 0x00, 0xAA, 0x00,
  0x55, 0x00, 0xAA, 0x89, 0x00, 0x0B, 0x20, 0x02, 0x88, 0x00, 0x42, 0x00, 0x08, 0x00, 0x00, 0x03,
  0x0F, 0x0C, 0x86, 0x18, 0x02, 0x1C, 0x0F, 0x07, 0x83, 0x00, 0x81, 0x1F, 0x82, 0x00, 0x87, 0xFF,
  0x12, 0x00, 0xFF, 0x80, 0xBF, 0xA0, 0xA1, 0xA1, 0xA0, 0xAC, 0xA0, 0xA1, 0xA1, 0xA0, 0xBF, 0x80,
  0xFF, 0x00, 0x1F, 0x1F, 0x89, 0x0C, 0x81, 0x1F, 0x82, 0x00, 0x02, 0xF0, 0xF8, 0x0C, 0x86, 0x00,
  0x02, 0x0C, 0xFC, 0xF0, 0x83, 0x00, 0x81, 0xFE, 0x89, 0xC0, 0x81, 0x00, 0x13, 0xFF, 0x02, 0xFA,
  0x0A, 0x0A, 0x0B, 0x08, 0x68, 0x08, 0x0B, 0x0A, 0x08, 0xF8, 0x00, 0xFF, 0x00, 0xE0, 0xF8, 0x1C,
  0x0C, 0x85, 0x06, 0x04, 0x0C, 0x1C, 0xF8, 0xE0, 0x00, 0x82, 0xFF, 0x01, 0xAA, 0x55, 0x87, 0x00,
  0x81, 0x01, 0x81, 0x03, 0x81, 0x04, 0x03, 0x0F, 0x00, 0x0F, 0x0F, 0x85, 0x00, 0x04, 0x78, 0xFC,
  0xCE, 0xC7, 0xFF, 0x83, 0x00, 0x08, 0xFF, 0x1F, 0x19, 0x10, 0x40, 0xC0, 0x10, 0x19, 0x00, 0x88,
  0xFF, 0x84, 0x00, 0x81, 0x01, 0x81, 0x03, 0x20, 0x01, 0x06, 0x0E, 0x0D, 0x1D, 0x03, 0x3F, 0x42,
  0x44, 0xFF, 0x84, 0x88, 0xFF, 0x08, 0x18, 0xFF, 0x21, 0x42, 0xFF, 0x00, 0xFF, 0xFF, 0x00, 0x1C,
  0x22, 0x49, 0x51, 0x41, 0x22, 0x1C, 0x00, 0x00, 0xFF, 0x83, 0x00, 0x09, 0xFF, 0xBF, 0xB3, 0xA1,
  0x00, 0x00, 0xA1, 0xB3, 0x00, 0xFF, 0x85, 0x00, 0x00, 0x0F, 0x82, 0x1F, 0x1E, 0x0F, 0xD0, 0xEF,
  0xF0, 0xF7, 0xE7, 0xFF, 0x00, 0xFF, 0x00, 0x7E, 0x00, 0xFF, 0xFF, 0x21, 0x21, 0xFF, 0x43, 0x43,
  0xFE, 0x46, 0x86, 0xFC, 0x0C, 0x08, 0xF8, 0x00, 0xF0, 0xF0, 0x00, 0x0E, 0x82, 0x11, 0x05, 0x0E,
  0x40, 0xA0, 0x40, 0x00, 0xE0, 0x83, 0x20, 0x00, 0xE0, 0x87, 0x20, 0x00, 0xE0, 0x85, 0x00, 0x11,
  0x8C, 0xDA, 0xD8, 0xD0, 0x80, 0x5C, 0xBC, 0x7C, 0x78, 0x78, 0xF8, 0xC0, 0xB0, 0xB0, 0x60, 0x60,
  0x80, 0xC0, 0x82, 0x80, 0x84, 0x00, 0x05, 0x18, 0x38, 0x60, 0x40, 0x64, 0x38, 0x84, 0x00, 0x81,
  0x04, 0x81, 0x0C, 0x03, 0x1C, 0x18, 0x38, 0x30, 0x82, 0x50, 0x81, 0x28, 0x81, 0x14, 0x00, 0x16,
  0x82, 0x0A, 0x81, 0x14, 0x12, 0x00, 0x38, 0x04, 0x18, 0x00, 0x10, 0x01, 0x0F, 0x00, 0x47, 0xEF,
  0xA9, 0xA9, 0x47, 0x30, 0xFF, 0x21, 0x1F, 0x07, 0x84, 0x00, 0x1E, 0xDD, 0x00, 0xBF, 0x00, 0x7F,
  0x7F, 0x00, 0xFF, 0x81, 0x08, 0x0C, 0x7E, 0x7E, 0x0C, 0x08, 0x81, 0xF0, 0xC0, 0x3F, 0x40, 0x7F,
  0x3F, 0x1F, 0x00, 0x10, 0x18, 0x18, 0x1C, 0x16, 0x13, 0x11, 0x88, 0x10, 0x83, 0x00, 0x2A, 0x0C,
  0x1C, 0x3C, 0xFC, 0xF8, 0xF8, 0xFC, 0xFE, 0xFF, 0xA7, 0xBB, 0xE7, 0x9C, 0xF8, 0xF0, 0xF0, 0x60,
  0x20, 0x00, 0x00, 0x7E, 0xCF, 0xFF, 0x00, 0xEE, 0xEE, 0xAA, 0x44, 0x3C, 0x7F, 0x37, 0x1F, 0x00,
  0xC6, 0xEE, 0xCC, 0x00, 0x00, 0xFF, 0x00, 0xED, 0x36, 0xCB, 0x86, 0x00, 0x08, 0x80, 0xC0, 0x60,
  0x30, 0x38, 0x18, 0x0C, 0x07, 0x07, 0x88, 0x00, 0x02, 0x38, 0x70, 0x70, 0x82, 0xF0, 0x06, 0xE0,
  0x20, 0xE0, 0xE0, 0x60, 0x60, 0x10, 0x85, 0x00, 0x02, 0xC0, 0xE0, 0xE0, 0x86, 0x00, 0x1A, 0xC0,
  0xE0, 0xE0, 0xF0, 0x0C, 0xF2, 0x0E, 0xFE, 0xFE, 0xF0, 0x00, 0xE1, 0xF1, 0xF9, 0xE1, 0xF1, 0xE1,
  0xF1, 0xE1, 0x00, 0x70, 0x7E, 0x0E, 0x70, 0x7E, 0x0E, 0x00, 0x87, 0x10, 0x01, 0x81, 0x3C, 0x83,
  0x7E, 0x08, 0x3C, 0x81, 0x00, 0x1C, 0x3E, 0x7F, 0xFF, 0x7F, 0x7F, 0x83, 0x00, 0x23, 0xC0, 0xE0,
  0xF8, 0xF0, 0x00, 0x08, 0x01, 0x40, 0x14, 0x01, 0x01, 0x03, 0x03, 0x07, 0x0F, 0x3F, 0x3F, 0x7F,
  0x6F, 0xBD, 0x56, 0x00, 0x08, 0x18, 0x3C, 0x7C, 0xBE, 0x55, 0x2A, 0x00, 0x20, 0x04, 0x10, 0x80,
  0x02, 0x20, 0xFE, 0x00, 0xFE, 0x00, 0xFE, 0x00, 0x83, 0x00, 0xFF};

const byte COLORRLEMENU[] = {
  0xFE, 0x41, 0xFE, 0x41, 0x89, 0x41, 0xFE, 0xF1, 0xFE, 0xF1, 0xFE, 0xF1, 0xF2, 0xF1, 0x87,
  0x41, 0xFE, 0xF1, 0xFC, 0xF1, 0x83, 0xF1, 0x87, 0x41, 0x87, 0xA1, 0x97, 0xF1, 0x87, 0x51, 0x8F,
  0xE1, 0xAF, 0xF1, 0x8F, 0xE1, 0x8F, 0xF1, 0x87, 0x41, 0x99, 0xE1, 0x83, 0x41, 0x01, 0xE1, 0x91,
  0x87, 0xE1, 0x87, 0x41, 0xA7, 0xE1, 0x01, 0x41, 0xE1, 0x83, 0x41, 0x01, 0xE1, 0x91, 0xEF, 0xE1,
  0x87, 0x31, 0x01, 0x21, 0x31, 0x83, 0x21, 0x81, 0xC1, 0x82, 0x21, 0x04, 0xC1, 0x21, 0x21, 0x31,
  0x21, 0x85, 0xF1, 0x81, 0x91, 0x85, 0xF1, 0x81, 0x91, 0x87, 0x81, 0x86, 0xB8, 0x01, 0x98, 0x1E,
  0x85, 0x6E, 0x02, 0x1E, 0x21, 0x2C, 0x85, 0x21, 0x87, 0x65, 0x87, 0xF5, 0x8F, 0x91, 0x8A, 0x81,
  0x84, 0xF1, 0x87, 0xB1, 0x83, 0x21, 0x82, 0x23, 0x00, 0x21, 0x8F, 0x65, 0x87, 0x41, 0x8F, 0x81,
  0x8F, 0x65, 0x87, 0x21, 0x87, 0x6A, 0x81, 0x61, 0x05, 0x91, 0x61, 0x61, 0x91, 0x61, 0x61, 0x87,
  0xF1, 0x87, 0xB5, 0x84, 0xF5, 0x01, 0xE1, 0x15, 0x85, 0xF5, 0x01, 0xE5, 0x15, 0x85, 0xF5, 0x83,
  0xE5, 0x00, 0x25, 0x82, 0xC5, 0x82, 0xBA, 0x8F, 0xD1, 0xFE, 0x41, 0xFE, 0x41, 0xFE, 0x41, 0x82,
  0x41, 0xFF};
