
#ifndef __HF_HTTPC_H_H__H___
#define __HF_HTTPC_H_H__H___


#define HTTPE_RECV_DATA			(0)
#define HTTPE_FAIL				(1)
#define HTTPE_COMPLETE			(2)

typedef struct _HF_HTTPC_EVENTDATA
{
	uint32_t eventid;
	char *data;
	int length;
}HF_HTTPC_EVENTDATA;

typedef int (*hfhttpe_callback_t)( HF_HTTPC_EVENTDATA *,void*);


typedef enum {
	HTTP_VER_1_0,
	HTTP_VER_1_1,
} http_ver_t;


typedef struct {
	const char *protocol;
	http_ver_t version;
	int status_code;
	const char *reason_phrase;	/* verbose string describing status code */
	const char *server;
	//time_t modify_time;	/* time when the resource was last modified */
	const char *content_type;
	const char *content_encoding;
	bool keep_alive_ack;
	int keep_alive_timeout;	/* Server timeout */
	int keep_alive_max;	/* Max time for which a persistent
				   connection will be open, irrespective of
				   connection activity  */
	bool chunked;
	uint32_t content_length;	/* This will be 0 if chunked == TRUE */
	char *redirect_url;
} http_resp_t;

typedef struct {
	char *name;
	char *value;
} http_header_pair_t;


int http_download_file(const char *url,hfhttpe_callback_t callback,void *ctx);


#endif


