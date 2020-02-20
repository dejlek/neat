#pragma once

#include <stdlib.h>

#include "type.h"

#define WORD_ALIGN(I) ((I + 7) & 0xfffffffffffffff8)
#define ASIZEOF(T) WORD_ALIGN(sizeof(T))

typedef struct {
    void *ptr;
    size_t length;
} Data;

typedef enum {
    DECLARE_SECTION,
    DEFINE_SECTION
} SectionKind;

typedef struct {
    SectionKind kind;
    int length; // including Section header
    // and then: data
} Section;

typedef struct {
    Section base;
    int declaration_index;
    int slots; // number of value slots
} DefineSection;

typedef struct {
    Data *data; // main file (where the types will be written)
    int start; // start of this section
    int blocks_start; // start of the blocks data (offsets)
} DefineSectionState;

typedef struct {
    Type type;
    int int_value;
} Value;