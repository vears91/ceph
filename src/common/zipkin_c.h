// -*- mode:C++; tab-width:8; c-basic-offset:2; indent-tabs-mode:t -*-
// vim: ts=8 sw=2 smarttab
#ifndef COMMON_ZIPKIN_C_H
#define COMMON_ZIPKIN_C_H

#ifdef WITH_BLKIN

#include <zipkin_c.h>

#else // !WITH_BLKIN

struct blkin_endpoint {};

struct blkin_trace_info {
    int64_t trace_id;
    int64_t span_id;
    int64_t parent_span_id;
};

struct blkin_trace_info_packed {};

struct blkin_trace {};

typedef enum {
} blkin_annotation_type;

struct blkin_annotation {};

int blkin_init() {}

int blkin_init_new_trace(struct blkin_trace *new_trace, const char *name,
       const struct blkin_endpoint *endpoint) {}


int blkin_init_child(struct blkin_trace *child,
         const struct blkin_trace *parent,
         const struct blkin_endpoint *endpoint,
         const char *child_name) {}

int blkin_init_child_info(struct blkin_trace *child,
        const struct blkin_trace_info *info,
        const struct blkin_endpoint *endpoint,
        const char *child_name) {}


int blkin_init_endpoint(struct blkin_endpoint *endpoint,
      const char *ip, int16_t port, const char *name) {}


int blkin_init_string_annotation(struct blkin_annotation *annotation,
         const char *key, const char *val,
         const struct blkin_endpoint *endpoint) {}

int blkin_init_integer_annotation(struct blkin_annotation *annotation,
          const char *key, int64_t val,
          const struct blkin_endpoint *endpoint) {}

int blkin_init_timestamp_annotation(struct blkin_annotation *annot,
            const char *event,
            const struct blkin_endpoint *endpoint) {}


int blkin_record(const struct blkin_trace *trace,
     const struct blkin_annotation *annotation) {}


int blkin_get_trace_info(const struct blkin_trace *trace,
       struct blkin_trace_info *info) {}

int blkin_set_trace_info(struct blkin_trace *trace,
       const struct blkin_trace_info *info) {}

int blkin_pack_trace_info(const struct blkin_trace_info *info,
        struct blkin_trace_info_packed *pinfo) {}

int blkin_unpack_trace_info(const struct blkin_trace_info_packed *pinfo,
          struct blkin_trace_info *info) {}

#endif // !WITH_BLKIN

#endif // COMMON_ZIPKIN_C_H
