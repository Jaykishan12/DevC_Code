#include "stdio.h"
#include "string.h"
#include "conio.h"
#include "stdint.h"

typedef int8_t json_obj_t;

static json_obj_t item_js[2048];

void create_json_object(json_obj_t *obj) {
	obj[0] = '{';
	obj[1] = '\n';
}

void array_list_json_new(json_obj_t *obj, int8_t *name) {
	strcat(obj, "\"");
	strcat(obj, name);
	strcat(obj, "\": [{\n");
}

void array_list_json_add(json_obj_t *obj) {
	if (',' == obj[strlen(obj) - 2])
		obj[strlen(obj) - 2] = obj[strlen(obj) - 1];
	obj[strlen(obj) - 1] = '}';
	strcat(obj, ",{\n");
}

void array_list_json_close(json_obj_t *obj) {
	int32_t len = strlen(obj);

	if (',' == obj[len - 3])
		obj[len - 3] = '\n';
	obj[len - 2] = ']';
	obj[len - 1] = '\n';
	obj[len] = ',';
}

void add_to_json_object(json_obj_t *obj, int8_t *key, int8_t *value) {
	strcat(obj, "\"");
	strcat(obj, key);
	strcat(obj, "\":\"");
	strcat(obj, value);
	strcat(obj, "\",\n");
}

void close_json_object(json_obj_t *obj) {
	if (',' == obj[strlen(obj) - 2])
		obj[strlen(obj) - 2] = obj[strlen(obj) - 1];
	obj[strlen(obj) - 1] = '}';
	obj[strlen(obj)] = '\0';
}


int main(){
	int8_t value[100];
	
	sprintf(value, "1");
	add_to_json_object(item_js, "ICODE", value);
	printf("%s",item_js);
	return 1;
}
