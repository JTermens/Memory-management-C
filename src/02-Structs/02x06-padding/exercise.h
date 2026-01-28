#pragma once

typedef struct SneklangVar
{
  char *name;       // 8 bytes
  int scope_level;  // 4 bytes
  int value;        // 4 bytes
  char is_constant; // 1 byte
  char type;        // 1 byte
} sneklang_var_t;
