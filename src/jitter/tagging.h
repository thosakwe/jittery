// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef JITTERY_TAGGING_H
#define JITTERY_TAGGING_H

#define JITTERY_TAG_INT 0x0
#define JITTERY_TAG_FLOAT 0x1
#define JITTERY_TAG_SMALL_STRING 0x2
#define JITTERY_TAG_STRING 0x3
#define JITTERY_TAG_TRUE 0x4
#define JITTERY_TAG_FALSE 0x5
#define JITTERY_TAG_OBJECT 0x6
#define JITTERY_TAG_NULL 0x7

#define JITTERY_GET_TAG(x) (((uint8_t) (x)) & JITTERY_TAG_NULL)

#define JITTERY_SET_TAG(x, type) ((x) & (type))

#define JITTERY_HAS_TAG(x, tag) JITTERY_GET_TAG((x)) == ((uint8_t) (tag))

#define JITTERY_GET_VALUE(x) ((x) >> 3)

#define JITTERY_SET_VALUE(x, value) (JITTERY_SET_TAG((value), JITTERY_GET_TAG((x))))

#define JITTERY_IS_NUMBER(x) (((x) >> 1) == 0)

#endif //JITTERY_TAGGING_H
