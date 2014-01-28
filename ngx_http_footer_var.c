#include "ngx_http_footer_var.h"

static ngx_http_variable_t ngx_http_footer_variables[] = {

    { ngx_string("footer_status"), NULL,
      ngx_http_footer_status_variable, 0,
      NGX_HTTP_VAR_NOCACHEABLE, 0 },
    { ngx_null_string, NULL, NULL, 0, 0, 0 }
};


static ngx_int_t
ngx_http_footer_status_variable(ngx_http_request_t *r,
    ngx_http_variable_value_t *v, uintptr_t data)
{
    ngx_http_footer_ctx_t *ctx;

    ctx = ngx_http_get_module_ctx(r, ngx_http_footer_filter_module);
    if (ctx == NULL) {
    }

    v->valid = 1;
    v->no_cacheable = 1;
    v->not_found = 0;

    return NGX_OK;
}


ngx_int_t
ngx_http_footer_add_variable(ngx_conf_t *cf)
{
    ngx_http_variable_t *var, *v;

    for (v = ngx_http_footer_variables; v->name.len; v++) {
        var = ngx_http_add_variable(cf, &v->name, v->flags);
        if (var == NULL) {
            return NGX_ERROR;
        }

        var->get_handler = v->get_handler;
        var->data = v->data;
    }

    return NGX_OK;
}

/* vi:set ft=c ts=4 sw=4 et fdm=marker: */
