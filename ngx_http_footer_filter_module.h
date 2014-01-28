#ifndef _NGX_HTTP_FOOTER_FILTER_MODULE_H_INCLUDED_
#define _NGX_HTTP_FOOTER_FILTER_MODULE_H_INCLUDED_

#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>

enum {
    NGX_HTTP_FOOTER_STATUS_BYPASS = 0,
    NGX_HTTP_FOOTER_STATUS_APPEND = 1
};

typedef struct {
    ngx_hash_t                types;
    ngx_array_t              *types_keys;
    ngx_http_complex_value_t *variable;
} ngx_http_footer_loc_conf_t;

typedef struct {
    ngx_str_t                 footer;
    unsigned                  append:1;
} ngx_http_footer_ctx_t;

#endif /* _NGX_HTTP_FOOTER_FILTER_MODULE_H_INCLUDED_ */
