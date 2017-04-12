/* Main.c generated by valac 0.30.1, the Vala compiler
 * generated from Main.vala, do not modify */

/**/
/*  Copyright (C) 2013 Tom Beckmann, Rico Tzschichholz*/
/**/
/*  This program is free software: you can redistribute it and/or modify*/
/*  it under the terms of the GNU General Public License as published by*/
/*  the Free Software Foundation, either version 3 of the License, or*/
/*  (at your option) any later version.*/
/**/
/*  This program is distributed in the hope that it will be useful,*/
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of*/
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the*/
/*  GNU General Public License for more details.*/
/**/
/*  You should have received a copy of the GNU General Public License*/
/*  along with this program.  If not, see <http://www.gnu.org/licenses/>.*/
/**/

#include <glib.h>
#include <glib-object.h>
#include "gala.h"
#include <float.h>
#include <math.h>
#include <meta/display.h>
#include <meta/meta-plugin.h>
#include <meta/screen.h>
#include <gio/gio.h>
#include "config.h"
#include <meta/prefs.h>
#include <meta/window.h>
#include <clutter/clutter.h>
#include <meta/keybindings.h>
#include <gdk/gdk.h>
#include <string.h>


#define GALA_PLUGINS_ZOOM_TYPE_MAIN (gala_plugins_zoom_main_get_type ())
#define GALA_PLUGINS_ZOOM_MAIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GALA_PLUGINS_ZOOM_TYPE_MAIN, GalaPluginsZoomMain))
#define GALA_PLUGINS_ZOOM_MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GALA_PLUGINS_ZOOM_TYPE_MAIN, GalaPluginsZoomMainClass))
#define GALA_PLUGINS_ZOOM_IS_MAIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GALA_PLUGINS_ZOOM_TYPE_MAIN))
#define GALA_PLUGINS_ZOOM_IS_MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GALA_PLUGINS_ZOOM_TYPE_MAIN))
#define GALA_PLUGINS_ZOOM_MAIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GALA_PLUGINS_ZOOM_TYPE_MAIN, GalaPluginsZoomMainClass))

typedef struct _GalaPluginsZoomMain GalaPluginsZoomMain;
typedef struct _GalaPluginsZoomMainClass GalaPluginsZoomMainClass;
typedef struct _GalaPluginsZoomMainPrivate GalaPluginsZoomMainPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _Block1Data Block1Data;
typedef struct _Block2Data Block2Data;
#define __vala_ClutterPoint_free0(var) ((var == NULL) ? NULL : (var = (_vala_ClutterPoint_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _GalaPluginsZoomMain {
	GalaPlugin parent_instance;
	GalaPluginsZoomMainPrivate * priv;
};

struct _GalaPluginsZoomMainClass {
	GalaPluginClass parent_class;
};

struct _GalaPluginsZoomMainPrivate {
	GalaWindowManager* wm;
	guint mouse_poll_timer;
	gfloat current_zoom;
	gulong wins_handler_id;
};

struct _Block1Data {
	int _ref_count_;
	GalaPluginsZoomMain* self;
	ClutterActor* wins;
};

struct _Block2Data {
	int _ref_count_;
	Block1Data * _data1_;
	gfloat mx;
	gfloat my;
	GdkDevice* client_pointer;
};


static gpointer gala_plugins_zoom_main_parent_class = NULL;

GType gala_plugins_zoom_main_get_type (void) G_GNUC_CONST;
#define GALA_PLUGINS_ZOOM_MAIN_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), GALA_PLUGINS_ZOOM_TYPE_MAIN, GalaPluginsZoomMainPrivate))
enum  {
	GALA_PLUGINS_ZOOM_MAIN_DUMMY_PROPERTY
};
#define GALA_PLUGINS_ZOOM_MAIN_MOUSE_POLL_TIME ((guint) 50)
static void gala_plugins_zoom_main_real_initialize (GalaPlugin* base, GalaWindowManager* wm);
static void gala_plugins_zoom_main_zoom_in (MetaDisplay* display, MetaScreen* screen, MetaWindow* window, ClutterKeyEvent* event, MetaKeyBinding* binding, GalaPluginsZoomMain* self);
static void gala_plugins_zoom_main_zoom_out (MetaDisplay* display, MetaScreen* screen, MetaWindow* window, ClutterKeyEvent* event, MetaKeyBinding* binding, GalaPluginsZoomMain* self);
static void gala_plugins_zoom_main_real_destroy (GalaPlugin* base);
static void gala_plugins_zoom_main_zoom (GalaPluginsZoomMain* self, gboolean in);
static Block1Data* block1_data_ref (Block1Data* _data1_);
static void block1_data_unref (void * _userdata_);
static Block2Data* block2_data_ref (Block2Data* _data2_);
static void block2_data_unref (void * _userdata_);
static gboolean ___lambda4_ (Block2Data* _data2_);
static void _vala_ClutterPoint_free (ClutterPoint* self);
static gboolean ____lambda4__gsource_func (gpointer self);
static void ___lambda5_ (Block1Data* _data1_);
static void ____lambda5__clutter_actor_transitions_completed (ClutterActor* _sender, gpointer self);
GalaPluginsZoomMain* gala_plugins_zoom_main_new (void);
GalaPluginsZoomMain* gala_plugins_zoom_main_construct (GType object_type);
static void gala_plugins_zoom_main_finalize (GObject* obj);
void register_plugin (GalaPluginInfo* result);


static gpointer _g_object_ref0 (gpointer self) {
#line 32 "/home/nick/work/gala/plugins/zoom/Main.vala"
	return self ? g_object_ref (self) : NULL;
#line 118 "Main.c"
}


static void gala_plugins_zoom_main_real_initialize (GalaPlugin* base, GalaWindowManager* wm) {
	GalaPluginsZoomMain * self;
	GalaWindowManager* _tmp0_ = NULL;
	GalaWindowManager* _tmp1_ = NULL;
	MetaDisplay* display = NULL;
	GalaWindowManager* _tmp2_ = NULL;
	MetaScreen* _tmp3_ = NULL;
	MetaDisplay* _tmp4_ = NULL;
	MetaDisplay* _tmp5_ = NULL;
	GSettings* schema = NULL;
	GSettings* _tmp6_ = NULL;
#line 30 "/home/nick/work/gala/plugins/zoom/Main.vala"
	self = (GalaPluginsZoomMain*) base;
#line 30 "/home/nick/work/gala/plugins/zoom/Main.vala"
	g_return_if_fail (wm != NULL);
#line 32 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp0_ = wm;
#line 32 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp1_ = _g_object_ref0 (_tmp0_);
#line 32 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_g_object_unref0 (self->priv->wm);
#line 32 "/home/nick/work/gala/plugins/zoom/Main.vala"
	self->priv->wm = _tmp1_;
#line 33 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp2_ = wm;
#line 33 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp3_ = meta_plugin_get_screen ((MetaPlugin*) _tmp2_);
#line 33 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp4_ = meta_screen_get_display (_tmp3_);
#line 33 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp5_ = _g_object_ref0 (_tmp4_);
#line 33 "/home/nick/work/gala/plugins/zoom/Main.vala"
	display = _tmp5_;
#line 34 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp6_ = g_settings_new (SCHEMA ".keybindings");
#line 34 "/home/nick/work/gala/plugins/zoom/Main.vala"
	schema = _tmp6_;
#line 36 "/home/nick/work/gala/plugins/zoom/Main.vala"
	meta_display_add_keybinding (display, "zoom-in", schema, 0, (MetaKeyHandlerFunc) gala_plugins_zoom_main_zoom_in, g_object_ref (self), NULL);
#line 37 "/home/nick/work/gala/plugins/zoom/Main.vala"
	meta_display_add_keybinding (display, "zoom-out", schema, 0, (MetaKeyHandlerFunc) gala_plugins_zoom_main_zoom_out, g_object_ref (self), NULL);
#line 30 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_g_object_unref0 (schema);
#line 30 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_g_object_unref0 (display);
#line 167 "Main.c"
}


static void gala_plugins_zoom_main_real_destroy (GalaPlugin* base) {
	GalaPluginsZoomMain * self;
	GalaWindowManager* _tmp0_ = NULL;
	MetaDisplay* display = NULL;
	GalaWindowManager* _tmp1_ = NULL;
	MetaScreen* _tmp2_ = NULL;
	MetaDisplay* _tmp3_ = NULL;
	MetaDisplay* _tmp4_ = NULL;
	MetaDisplay* _tmp5_ = NULL;
	MetaDisplay* _tmp6_ = NULL;
	guint _tmp7_ = 0U;
#line 40 "/home/nick/work/gala/plugins/zoom/Main.vala"
	self = (GalaPluginsZoomMain*) base;
#line 42 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp0_ = self->priv->wm;
#line 42 "/home/nick/work/gala/plugins/zoom/Main.vala"
	if (_tmp0_ == NULL) {
#line 43 "/home/nick/work/gala/plugins/zoom/Main.vala"
		return;
#line 190 "Main.c"
	}
#line 45 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp1_ = self->priv->wm;
#line 45 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp2_ = meta_plugin_get_screen ((MetaPlugin*) _tmp1_);
#line 45 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp3_ = meta_screen_get_display (_tmp2_);
#line 45 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp4_ = _g_object_ref0 (_tmp3_);
#line 45 "/home/nick/work/gala/plugins/zoom/Main.vala"
	display = _tmp4_;
#line 47 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp5_ = display;
#line 47 "/home/nick/work/gala/plugins/zoom/Main.vala"
	meta_display_remove_keybinding (_tmp5_, "zoom-in");
#line 48 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp6_ = display;
#line 48 "/home/nick/work/gala/plugins/zoom/Main.vala"
	meta_display_remove_keybinding (_tmp6_, "zoom-out");
#line 50 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp7_ = self->priv->mouse_poll_timer;
#line 50 "/home/nick/work/gala/plugins/zoom/Main.vala"
	if (_tmp7_ > ((guint) 0)) {
#line 214 "Main.c"
		guint _tmp8_ = 0U;
#line 51 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp8_ = self->priv->mouse_poll_timer;
#line 51 "/home/nick/work/gala/plugins/zoom/Main.vala"
		g_source_remove (_tmp8_);
#line 220 "Main.c"
	}
#line 52 "/home/nick/work/gala/plugins/zoom/Main.vala"
	self->priv->mouse_poll_timer = (guint) 0;
#line 40 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_g_object_unref0 (display);
#line 226 "Main.c"
}


static void gala_plugins_zoom_main_zoom_in (MetaDisplay* display, MetaScreen* screen, MetaWindow* window, ClutterKeyEvent* event, MetaKeyBinding* binding, GalaPluginsZoomMain* self) {
#line 56 "/home/nick/work/gala/plugins/zoom/Main.vala"
	g_return_if_fail (self != NULL);
#line 56 "/home/nick/work/gala/plugins/zoom/Main.vala"
	g_return_if_fail (display != NULL);
#line 56 "/home/nick/work/gala/plugins/zoom/Main.vala"
	g_return_if_fail (screen != NULL);
#line 56 "/home/nick/work/gala/plugins/zoom/Main.vala"
	g_return_if_fail (event != NULL);
#line 56 "/home/nick/work/gala/plugins/zoom/Main.vala"
	g_return_if_fail (binding != NULL);
#line 59 "/home/nick/work/gala/plugins/zoom/Main.vala"
	gala_plugins_zoom_main_zoom (self, TRUE);
#line 243 "Main.c"
}


static void gala_plugins_zoom_main_zoom_out (MetaDisplay* display, MetaScreen* screen, MetaWindow* window, ClutterKeyEvent* event, MetaKeyBinding* binding, GalaPluginsZoomMain* self) {
#line 63 "/home/nick/work/gala/plugins/zoom/Main.vala"
	g_return_if_fail (self != NULL);
#line 63 "/home/nick/work/gala/plugins/zoom/Main.vala"
	g_return_if_fail (display != NULL);
#line 63 "/home/nick/work/gala/plugins/zoom/Main.vala"
	g_return_if_fail (screen != NULL);
#line 63 "/home/nick/work/gala/plugins/zoom/Main.vala"
	g_return_if_fail (event != NULL);
#line 63 "/home/nick/work/gala/plugins/zoom/Main.vala"
	g_return_if_fail (binding != NULL);
#line 66 "/home/nick/work/gala/plugins/zoom/Main.vala"
	gala_plugins_zoom_main_zoom (self, FALSE);
#line 260 "Main.c"
}


static Block1Data* block1_data_ref (Block1Data* _data1_) {
#line 69 "/home/nick/work/gala/plugins/zoom/Main.vala"
	g_atomic_int_inc (&_data1_->_ref_count_);
#line 69 "/home/nick/work/gala/plugins/zoom/Main.vala"
	return _data1_;
#line 269 "Main.c"
}


static void block1_data_unref (void * _userdata_) {
	Block1Data* _data1_;
	_data1_ = (Block1Data*) _userdata_;
#line 69 "/home/nick/work/gala/plugins/zoom/Main.vala"
	if (g_atomic_int_dec_and_test (&_data1_->_ref_count_)) {
#line 278 "Main.c"
		GalaPluginsZoomMain* self;
#line 69 "/home/nick/work/gala/plugins/zoom/Main.vala"
		self = _data1_->self;
#line 69 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_g_object_unref0 (_data1_->wins);
#line 69 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_g_object_unref0 (self);
#line 69 "/home/nick/work/gala/plugins/zoom/Main.vala"
		g_slice_free (Block1Data, _data1_);
#line 288 "Main.c"
	}
}


static Block2Data* block2_data_ref (Block2Data* _data2_) {
#line 81 "/home/nick/work/gala/plugins/zoom/Main.vala"
	g_atomic_int_inc (&_data2_->_ref_count_);
#line 81 "/home/nick/work/gala/plugins/zoom/Main.vala"
	return _data2_;
#line 298 "Main.c"
}


static void block2_data_unref (void * _userdata_) {
	Block2Data* _data2_;
	_data2_ = (Block2Data*) _userdata_;
#line 81 "/home/nick/work/gala/plugins/zoom/Main.vala"
	if (g_atomic_int_dec_and_test (&_data2_->_ref_count_)) {
#line 307 "Main.c"
		GalaPluginsZoomMain* self;
#line 81 "/home/nick/work/gala/plugins/zoom/Main.vala"
		self = _data2_->_data1_->self;
#line 81 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_g_object_unref0 (_data2_->client_pointer);
#line 81 "/home/nick/work/gala/plugins/zoom/Main.vala"
		block1_data_unref (_data2_->_data1_);
#line 81 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_data2_->_data1_ = NULL;
#line 81 "/home/nick/work/gala/plugins/zoom/Main.vala"
		g_slice_free (Block2Data, _data2_);
#line 319 "Main.c"
	}
}


static void _vala_ClutterPoint_free (ClutterPoint* self) {
#line 91 "/home/nick/work/gala/plugins/zoom/Main.vala"
	g_boxed_free (clutter_point_get_type (), self);
#line 327 "Main.c"
}


static gboolean ___lambda4_ (Block2Data* _data2_) {
	Block1Data* _data1_;
	GalaPluginsZoomMain* self;
	gboolean result = FALSE;
	GdkDevice* _tmp0_ = NULL;
	gint _tmp1_ = 0;
	gint _tmp2_ = 0;
	ClutterPoint* new_pivot = NULL;
	ClutterPoint* _tmp3_ = NULL;
	ClutterPoint* _tmp4_ = NULL;
	gfloat _tmp5_ = 0.0F;
	ClutterActor* _tmp6_ = NULL;
	gfloat _tmp7_ = 0.0F;
	gfloat _tmp8_ = 0.0F;
	gfloat _tmp9_ = 0.0F;
	ClutterActor* _tmp10_ = NULL;
	gfloat _tmp11_ = 0.0F;
	gfloat _tmp12_ = 0.0F;
	ClutterActor* _tmp13_ = NULL;
	ClutterPoint* _tmp14_ = NULL;
	ClutterPoint* _tmp15_ = NULL;
	ClutterPoint* _tmp16_ = NULL;
	ClutterPoint* _tmp17_ = NULL;
	gboolean _tmp18_ = FALSE;
	gboolean _tmp19_ = FALSE;
	ClutterActor* _tmp20_ = NULL;
	ClutterActor* _tmp21_ = NULL;
	ClutterActor* _tmp22_ = NULL;
	ClutterActor* _tmp23_ = NULL;
	ClutterPoint* _tmp24_ = NULL;
	ClutterActor* _tmp25_ = NULL;
#line 87 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_data1_ = _data2_->_data1_;
#line 87 "/home/nick/work/gala/plugins/zoom/Main.vala"
	self = _data1_->self;
#line 88 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp0_ = _data2_->client_pointer;
#line 88 "/home/nick/work/gala/plugins/zoom/Main.vala"
	gdk_device_get_position (_tmp0_, NULL, &_tmp1_, &_tmp2_);
#line 88 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_data2_->mx = (gfloat) _tmp1_;
#line 88 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_data2_->my = (gfloat) _tmp2_;
#line 89 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp3_ = clutter_point_alloc ();
#line 89 "/home/nick/work/gala/plugins/zoom/Main.vala"
	new_pivot = _tmp3_;
#line 90 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp4_ = new_pivot;
#line 90 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp5_ = _data2_->mx;
#line 90 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp6_ = _data1_->wins;
#line 90 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp7_ = clutter_actor_get_width (_tmp6_);
#line 90 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp8_ = _tmp7_;
#line 90 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp9_ = _data2_->my;
#line 90 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp10_ = _data1_->wins;
#line 90 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp11_ = clutter_actor_get_height (_tmp10_);
#line 90 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp12_ = _tmp11_;
#line 90 "/home/nick/work/gala/plugins/zoom/Main.vala"
	clutter_point_init (_tmp4_, _tmp5_ / _tmp8_, _tmp9_ / _tmp12_);
#line 91 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp13_ = _data1_->wins;
#line 91 "/home/nick/work/gala/plugins/zoom/Main.vala"
	g_object_get (_tmp13_, "pivot-point", &_tmp14_, NULL);
#line 91 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp15_ = _tmp14_;
#line 91 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp16_ = _tmp15_;
#line 91 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp17_ = new_pivot;
#line 91 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp18_ = clutter_point_equals (_tmp16_, _tmp17_);
#line 91 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp19_ = _tmp18_;
#line 91 "/home/nick/work/gala/plugins/zoom/Main.vala"
	__vala_ClutterPoint_free0 (_tmp16_);
#line 91 "/home/nick/work/gala/plugins/zoom/Main.vala"
	if (_tmp19_) {
#line 92 "/home/nick/work/gala/plugins/zoom/Main.vala"
		result = TRUE;
#line 92 "/home/nick/work/gala/plugins/zoom/Main.vala"
		__vala_ClutterPoint_free0 (new_pivot);
#line 92 "/home/nick/work/gala/plugins/zoom/Main.vala"
		return result;
#line 422 "Main.c"
	}
#line 94 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp20_ = _data1_->wins;
#line 94 "/home/nick/work/gala/plugins/zoom/Main.vala"
	clutter_actor_save_easing_state (_tmp20_);
#line 95 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp21_ = _data1_->wins;
#line 95 "/home/nick/work/gala/plugins/zoom/Main.vala"
	clutter_actor_set_easing_mode (_tmp21_, CLUTTER_LINEAR);
#line 96 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp22_ = _data1_->wins;
#line 96 "/home/nick/work/gala/plugins/zoom/Main.vala"
	clutter_actor_set_easing_duration (_tmp22_, GALA_PLUGINS_ZOOM_MAIN_MOUSE_POLL_TIME);
#line 97 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp23_ = _data1_->wins;
#line 97 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp24_ = new_pivot;
#line 97 "/home/nick/work/gala/plugins/zoom/Main.vala"
	g_object_set (_tmp23_, "pivot-point", _tmp24_, NULL);
#line 98 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp25_ = _data1_->wins;
#line 98 "/home/nick/work/gala/plugins/zoom/Main.vala"
	clutter_actor_restore_easing_state (_tmp25_);
#line 99 "/home/nick/work/gala/plugins/zoom/Main.vala"
	result = TRUE;
#line 99 "/home/nick/work/gala/plugins/zoom/Main.vala"
	__vala_ClutterPoint_free0 (new_pivot);
#line 99 "/home/nick/work/gala/plugins/zoom/Main.vala"
	return result;
#line 452 "Main.c"
}


static gboolean ____lambda4__gsource_func (gpointer self) {
	gboolean result;
	result = ___lambda4_ (self);
#line 87 "/home/nick/work/gala/plugins/zoom/Main.vala"
	return result;
#line 461 "Main.c"
}


static void ___lambda5_ (Block1Data* _data1_) {
	GalaPluginsZoomMain* self;
	ClutterActor* _tmp0_ = NULL;
	gulong _tmp1_ = 0UL;
	ClutterActor* _tmp2_ = NULL;
#line 118 "/home/nick/work/gala/plugins/zoom/Main.vala"
	self = _data1_->self;
#line 119 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp0_ = _data1_->wins;
#line 119 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp1_ = self->priv->wins_handler_id;
#line 119 "/home/nick/work/gala/plugins/zoom/Main.vala"
	g_signal_handler_disconnect ((GObject*) _tmp0_, _tmp1_);
#line 120 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp2_ = _data1_->wins;
#line 120 "/home/nick/work/gala/plugins/zoom/Main.vala"
	clutter_actor_set_pivot_point (_tmp2_, 0.0f, 0.0f);
#line 482 "Main.c"
}


static void ____lambda5__clutter_actor_transitions_completed (ClutterActor* _sender, gpointer self) {
#line 118 "/home/nick/work/gala/plugins/zoom/Main.vala"
	___lambda5_ (self);
#line 489 "Main.c"
}


static void gala_plugins_zoom_main_zoom (GalaPluginsZoomMain* self, gboolean in) {
	Block1Data* _data1_;
	gboolean _tmp0_ = FALSE;
	gfloat _tmp1_ = 0.0F;
	GalaWindowManager* _tmp6_ = NULL;
	ClutterActor* _tmp7_ = NULL;
	ClutterActor* _tmp8_ = NULL;
	ClutterActor* _tmp9_ = NULL;
	guint _tmp10_ = 0U;
	gfloat _tmp28_ = 0.0F;
	gboolean _tmp29_ = FALSE;
	gfloat _tmp30_ = 0.0F;
	gfloat _tmp31_ = 0.0F;
	ClutterActor* _tmp41_ = NULL;
	ClutterActor* _tmp42_ = NULL;
	ClutterActor* _tmp43_ = NULL;
	ClutterActor* _tmp44_ = NULL;
	gfloat _tmp45_ = 0.0F;
	gfloat _tmp46_ = 0.0F;
	ClutterActor* _tmp47_ = NULL;
#line 69 "/home/nick/work/gala/plugins/zoom/Main.vala"
	g_return_if_fail (self != NULL);
#line 69 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_data1_ = g_slice_new0 (Block1Data);
#line 69 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_data1_->_ref_count_ = 1;
#line 69 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_data1_->self = g_object_ref (self);
#line 72 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp1_ = self->priv->current_zoom;
#line 72 "/home/nick/work/gala/plugins/zoom/Main.vala"
	if (_tmp1_ <= 1.0f) {
#line 525 "Main.c"
		gboolean _tmp2_ = FALSE;
#line 72 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp2_ = in;
#line 72 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp0_ = !_tmp2_;
#line 531 "Main.c"
	} else {
#line 72 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp0_ = FALSE;
#line 535 "Main.c"
	}
#line 72 "/home/nick/work/gala/plugins/zoom/Main.vala"
	if (_tmp0_) {
#line 73 "/home/nick/work/gala/plugins/zoom/Main.vala"
		block1_data_unref (_data1_);
#line 73 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_data1_ = NULL;
#line 73 "/home/nick/work/gala/plugins/zoom/Main.vala"
		return;
#line 545 "Main.c"
	} else {
		gboolean _tmp3_ = FALSE;
		gfloat _tmp4_ = 0.0F;
#line 74 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp4_ = self->priv->current_zoom;
#line 74 "/home/nick/work/gala/plugins/zoom/Main.vala"
		if (_tmp4_ >= 2.5f) {
#line 553 "Main.c"
			gboolean _tmp5_ = FALSE;
#line 74 "/home/nick/work/gala/plugins/zoom/Main.vala"
			_tmp5_ = in;
#line 74 "/home/nick/work/gala/plugins/zoom/Main.vala"
			_tmp3_ = _tmp5_;
#line 559 "Main.c"
		} else {
#line 74 "/home/nick/work/gala/plugins/zoom/Main.vala"
			_tmp3_ = FALSE;
#line 563 "Main.c"
		}
#line 74 "/home/nick/work/gala/plugins/zoom/Main.vala"
		if (_tmp3_) {
#line 75 "/home/nick/work/gala/plugins/zoom/Main.vala"
			block1_data_unref (_data1_);
#line 75 "/home/nick/work/gala/plugins/zoom/Main.vala"
			_data1_ = NULL;
#line 75 "/home/nick/work/gala/plugins/zoom/Main.vala"
			return;
#line 573 "Main.c"
		}
	}
#line 77 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp6_ = self->priv->wm;
#line 77 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp7_ = gala_window_manager_get_ui_group (_tmp6_);
#line 77 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp8_ = _tmp7_;
#line 77 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp9_ = _g_object_ref0 (_tmp8_);
#line 77 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_data1_->wins = _tmp9_;
#line 81 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp10_ = self->priv->mouse_poll_timer;
#line 81 "/home/nick/work/gala/plugins/zoom/Main.vala"
	if (_tmp10_ == ((guint) 0)) {
#line 590 "Main.c"
		Block2Data* _data2_;
		GdkDisplay* _tmp11_ = NULL;
		GdkDeviceManager* _tmp12_ = NULL;
		GdkDevice* _tmp13_ = NULL;
		GdkDevice* _tmp14_ = NULL;
		GdkDevice* _tmp15_ = NULL;
		gint _tmp16_ = 0;
		gint _tmp17_ = 0;
		ClutterActor* _tmp18_ = NULL;
		gfloat _tmp19_ = 0.0F;
		ClutterActor* _tmp20_ = NULL;
		gfloat _tmp21_ = 0.0F;
		gfloat _tmp22_ = 0.0F;
		gfloat _tmp23_ = 0.0F;
		ClutterActor* _tmp24_ = NULL;
		gfloat _tmp25_ = 0.0F;
		gfloat _tmp26_ = 0.0F;
		guint _tmp27_ = 0U;
#line 81 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_data2_ = g_slice_new0 (Block2Data);
#line 81 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_data2_->_ref_count_ = 1;
#line 81 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_data2_->_data1_ = block1_data_ref (_data1_);
#line 83 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp11_ = gdk_display_get_default ();
#line 83 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp12_ = gdk_display_get_device_manager (_tmp11_);
#line 83 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp13_ = gdk_device_manager_get_client_pointer (_tmp12_);
#line 83 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp14_ = _g_object_ref0 (_tmp13_);
#line 83 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_data2_->client_pointer = _tmp14_;
#line 84 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp15_ = _data2_->client_pointer;
#line 84 "/home/nick/work/gala/plugins/zoom/Main.vala"
		gdk_device_get_position (_tmp15_, NULL, &_tmp16_, &_tmp17_);
#line 84 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_data2_->mx = (gfloat) _tmp16_;
#line 84 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_data2_->my = (gfloat) _tmp17_;
#line 85 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp18_ = _data1_->wins;
#line 85 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp19_ = _data2_->mx;
#line 85 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp20_ = _data1_->wins;
#line 85 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp21_ = clutter_actor_get_width (_tmp20_);
#line 85 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp22_ = _tmp21_;
#line 85 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp23_ = _data2_->my;
#line 85 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp24_ = _data1_->wins;
#line 85 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp25_ = clutter_actor_get_height (_tmp24_);
#line 85 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp26_ = _tmp25_;
#line 85 "/home/nick/work/gala/plugins/zoom/Main.vala"
		clutter_actor_set_pivot_point (_tmp18_, _tmp19_ / _tmp22_, _tmp23_ / _tmp26_);
#line 87 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp27_ = g_timeout_add_full (G_PRIORITY_DEFAULT, GALA_PLUGINS_ZOOM_MAIN_MOUSE_POLL_TIME, ____lambda4__gsource_func, block2_data_ref (_data2_), block2_data_unref);
#line 87 "/home/nick/work/gala/plugins/zoom/Main.vala"
		self->priv->mouse_poll_timer = _tmp27_;
#line 81 "/home/nick/work/gala/plugins/zoom/Main.vala"
		block2_data_unref (_data2_);
#line 81 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_data2_ = NULL;
#line 661 "Main.c"
	}
#line 103 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp29_ = in;
#line 103 "/home/nick/work/gala/plugins/zoom/Main.vala"
	if (_tmp29_) {
#line 103 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp28_ = 0.5f;
#line 669 "Main.c"
	} else {
#line 103 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp28_ = -0.5f;
#line 673 "Main.c"
	}
#line 103 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp30_ = self->priv->current_zoom;
#line 103 "/home/nick/work/gala/plugins/zoom/Main.vala"
	self->priv->current_zoom = _tmp30_ + _tmp28_;
#line 105 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp31_ = self->priv->current_zoom;
#line 105 "/home/nick/work/gala/plugins/zoom/Main.vala"
	if (_tmp31_ <= 1.0f) {
#line 683 "Main.c"
		guint _tmp32_ = 0U;
		ClutterActor* _tmp34_ = NULL;
		ClutterActor* _tmp35_ = NULL;
		ClutterActor* _tmp36_ = NULL;
		ClutterActor* _tmp37_ = NULL;
		ClutterActor* _tmp38_ = NULL;
		ClutterActor* _tmp39_ = NULL;
		gulong _tmp40_ = 0UL;
#line 106 "/home/nick/work/gala/plugins/zoom/Main.vala"
		self->priv->current_zoom = 1.0f;
#line 108 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp32_ = self->priv->mouse_poll_timer;
#line 108 "/home/nick/work/gala/plugins/zoom/Main.vala"
		if (_tmp32_ > ((guint) 0)) {
#line 698 "Main.c"
			guint _tmp33_ = 0U;
#line 109 "/home/nick/work/gala/plugins/zoom/Main.vala"
			_tmp33_ = self->priv->mouse_poll_timer;
#line 109 "/home/nick/work/gala/plugins/zoom/Main.vala"
			g_source_remove (_tmp33_);
#line 704 "Main.c"
		}
#line 110 "/home/nick/work/gala/plugins/zoom/Main.vala"
		self->priv->mouse_poll_timer = (guint) 0;
#line 112 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp34_ = _data1_->wins;
#line 112 "/home/nick/work/gala/plugins/zoom/Main.vala"
		clutter_actor_save_easing_state (_tmp34_);
#line 113 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp35_ = _data1_->wins;
#line 113 "/home/nick/work/gala/plugins/zoom/Main.vala"
		clutter_actor_set_easing_mode (_tmp35_, CLUTTER_EASE_OUT_CUBIC);
#line 114 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp36_ = _data1_->wins;
#line 114 "/home/nick/work/gala/plugins/zoom/Main.vala"
		clutter_actor_set_easing_duration (_tmp36_, (guint) 300);
#line 115 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp37_ = _data1_->wins;
#line 115 "/home/nick/work/gala/plugins/zoom/Main.vala"
		clutter_actor_set_scale (_tmp37_, (gdouble) 1.0f, (gdouble) 1.0f);
#line 116 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp38_ = _data1_->wins;
#line 116 "/home/nick/work/gala/plugins/zoom/Main.vala"
		clutter_actor_restore_easing_state (_tmp38_);
#line 118 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp39_ = _data1_->wins;
#line 118 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_tmp40_ = g_signal_connect_data (_tmp39_, "transitions-completed", (GCallback) ____lambda5__clutter_actor_transitions_completed, block1_data_ref (_data1_), (GClosureNotify) block1_data_unref, 0);
#line 118 "/home/nick/work/gala/plugins/zoom/Main.vala"
		self->priv->wins_handler_id = _tmp40_;
#line 123 "/home/nick/work/gala/plugins/zoom/Main.vala"
		block1_data_unref (_data1_);
#line 123 "/home/nick/work/gala/plugins/zoom/Main.vala"
		_data1_ = NULL;
#line 123 "/home/nick/work/gala/plugins/zoom/Main.vala"
		return;
#line 740 "Main.c"
	}
#line 126 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp41_ = _data1_->wins;
#line 126 "/home/nick/work/gala/plugins/zoom/Main.vala"
	clutter_actor_save_easing_state (_tmp41_);
#line 127 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp42_ = _data1_->wins;
#line 127 "/home/nick/work/gala/plugins/zoom/Main.vala"
	clutter_actor_set_easing_mode (_tmp42_, CLUTTER_EASE_OUT_CUBIC);
#line 128 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp43_ = _data1_->wins;
#line 128 "/home/nick/work/gala/plugins/zoom/Main.vala"
	clutter_actor_set_easing_duration (_tmp43_, (guint) 300);
#line 129 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp44_ = _data1_->wins;
#line 129 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp45_ = self->priv->current_zoom;
#line 129 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp46_ = self->priv->current_zoom;
#line 129 "/home/nick/work/gala/plugins/zoom/Main.vala"
	clutter_actor_set_scale (_tmp44_, (gdouble) _tmp45_, (gdouble) _tmp46_);
#line 130 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp47_ = _data1_->wins;
#line 130 "/home/nick/work/gala/plugins/zoom/Main.vala"
	clutter_actor_restore_easing_state (_tmp47_);
#line 69 "/home/nick/work/gala/plugins/zoom/Main.vala"
	block1_data_unref (_data1_);
#line 69 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_data1_ = NULL;
#line 770 "Main.c"
}


GalaPluginsZoomMain* gala_plugins_zoom_main_construct (GType object_type) {
	GalaPluginsZoomMain * self = NULL;
#line 20 "/home/nick/work/gala/plugins/zoom/Main.vala"
	self = (GalaPluginsZoomMain*) gala_plugin_construct (object_type);
#line 20 "/home/nick/work/gala/plugins/zoom/Main.vala"
	return self;
#line 780 "Main.c"
}


GalaPluginsZoomMain* gala_plugins_zoom_main_new (void) {
#line 20 "/home/nick/work/gala/plugins/zoom/Main.vala"
	return gala_plugins_zoom_main_construct (GALA_PLUGINS_ZOOM_TYPE_MAIN);
#line 787 "Main.c"
}


static void gala_plugins_zoom_main_class_init (GalaPluginsZoomMainClass * klass) {
#line 20 "/home/nick/work/gala/plugins/zoom/Main.vala"
	gala_plugins_zoom_main_parent_class = g_type_class_peek_parent (klass);
#line 20 "/home/nick/work/gala/plugins/zoom/Main.vala"
	g_type_class_add_private (klass, sizeof (GalaPluginsZoomMainPrivate));
#line 20 "/home/nick/work/gala/plugins/zoom/Main.vala"
	((GalaPluginClass *) klass)->initialize = gala_plugins_zoom_main_real_initialize;
#line 20 "/home/nick/work/gala/plugins/zoom/Main.vala"
	((GalaPluginClass *) klass)->destroy = gala_plugins_zoom_main_real_destroy;
#line 20 "/home/nick/work/gala/plugins/zoom/Main.vala"
	G_OBJECT_CLASS (klass)->finalize = gala_plugins_zoom_main_finalize;
#line 802 "Main.c"
}


static void gala_plugins_zoom_main_instance_init (GalaPluginsZoomMain * self) {
#line 20 "/home/nick/work/gala/plugins/zoom/Main.vala"
	self->priv = GALA_PLUGINS_ZOOM_MAIN_GET_PRIVATE (self);
#line 24 "/home/nick/work/gala/plugins/zoom/Main.vala"
	self->priv->wm = NULL;
#line 26 "/home/nick/work/gala/plugins/zoom/Main.vala"
	self->priv->mouse_poll_timer = (guint) 0;
#line 27 "/home/nick/work/gala/plugins/zoom/Main.vala"
	self->priv->current_zoom = 1.0f;
#line 28 "/home/nick/work/gala/plugins/zoom/Main.vala"
	self->priv->wins_handler_id = 0UL;
#line 817 "Main.c"
}


static void gala_plugins_zoom_main_finalize (GObject* obj) {
	GalaPluginsZoomMain * self;
#line 20 "/home/nick/work/gala/plugins/zoom/Main.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, GALA_PLUGINS_ZOOM_TYPE_MAIN, GalaPluginsZoomMain);
#line 24 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_g_object_unref0 (self->priv->wm);
#line 20 "/home/nick/work/gala/plugins/zoom/Main.vala"
	G_OBJECT_CLASS (gala_plugins_zoom_main_parent_class)->finalize (obj);
#line 829 "Main.c"
}


GType gala_plugins_zoom_main_get_type (void) {
	static volatile gsize gala_plugins_zoom_main_type_id__volatile = 0;
	if (g_once_init_enter (&gala_plugins_zoom_main_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (GalaPluginsZoomMainClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gala_plugins_zoom_main_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (GalaPluginsZoomMain), 0, (GInstanceInitFunc) gala_plugins_zoom_main_instance_init, NULL };
		GType gala_plugins_zoom_main_type_id;
		gala_plugins_zoom_main_type_id = g_type_register_static (GALA_TYPE_PLUGIN, "GalaPluginsZoomMain", &g_define_type_info, 0);
		g_once_init_leave (&gala_plugins_zoom_main_type_id__volatile, gala_plugins_zoom_main_type_id);
	}
	return gala_plugins_zoom_main_type_id__volatile;
}


void register_plugin (GalaPluginInfo* result) {
	gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	GalaPluginInfo _tmp2_ = {0};
#line 137 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp0_ = g_strdup ("Zoom");
#line 137 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp1_ = g_strdup ("Gala Developers");
#line 137 "/home/nick/work/gala/plugins/zoom/Main.vala"
	memset (&_tmp2_, 0, sizeof (GalaPluginInfo));
#line 137 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_g_free0 (_tmp2_.name);
#line 137 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp2_.name = _tmp0_;
#line 137 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_g_free0 (_tmp2_.author);
#line 137 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp2_.author = _tmp1_;
#line 137 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp2_.plugin_type = GALA_PLUGINS_ZOOM_TYPE_MAIN;
#line 137 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp2_.provides = GALA_PLUGIN_FUNCTION_ADDITION;
#line 137 "/home/nick/work/gala/plugins/zoom/Main.vala"
	_tmp2_.load_priority = GALA_LOAD_PRIORITY_IMMEDIATE;
#line 137 "/home/nick/work/gala/plugins/zoom/Main.vala"
	*result = _tmp2_;
#line 137 "/home/nick/work/gala/plugins/zoom/Main.vala"
	return;
#line 873 "Main.c"
}


