/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * g37-multi_window.c
 * Copyright (C) 2022 tiger <tiger@loongnix>
 * 
 * g37-multi_window is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * g37-multi_window is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "g37-multi_window.h"

#include <glib/gi18n.h>
#include "hello.h"


/* For testing propose use the local (not installed) ui file */
/* #define UI_FILE PACKAGE_DATA_DIR"/ui/g37_multi_window.ui" */
#define UI_FILE "src/g37_multi_window.ui"
#define TOP_WINDOW "window"


G_DEFINE_TYPE (G37multi_Window, g37_multi_window, GTK_TYPE_APPLICATION);

/* ANJUTA: Macro G37_MULTI_WINDOW_APPLICATION gets G37multi_Window - DO NOT REMOVE */
struct _G37multi_WindowPrivate
{
	/* ANJUTA: Widgets declaration for g37_multi_window.ui - DO NOT REMOVE */
};

/* Create a new window loading a file */
static void
g37_multi_window_new_window (GApplication *app,
                           GFile        *file)
{
	GtkWidget *window;

	GtkBuilder *builder;
	GError* error = NULL;

	G37multi_WindowPrivate *priv = G37_MULTI_WINDOW_APPLICATION(app)->priv;

	/* Load UI from file */
	builder = gtk_builder_new ();
	if (!gtk_builder_add_from_file (builder, UI_FILE, &error))
	{
		g_critical ("Couldn't load builder file: %s", error->message);
		g_error_free (error);
	}

	/* Auto-connect signal handlers */
	gtk_builder_connect_signals (builder, app);

	/* Get the window object from the ui file */
	window = GTK_WIDGET (gtk_builder_get_object (builder, TOP_WINDOW));
        if (!window)
        {
		g_critical ("Widget \"%s\" is missing in file %s.",
				TOP_WINDOW,
				UI_FILE);
        }

	
	/* ANJUTA: Widgets initialization for g37_multi_window.ui - DO NOT REMOVE */

	g_object_unref (builder);
	
	
	gtk_window_set_application (GTK_WINDOW (window), GTK_APPLICATION (app));
	if (file != NULL)
	{
		/* TODO: Add code here to open the file in the new window */
	}

	gtk_widget_show_all (GTK_WIDGET (window));
}


/* GApplication implementation */
static void
g37_multi_window_activate (GApplication *application)
{
	g37_multi_window_new_window (application, NULL);
}

static void
g37_multi_window_open (GApplication  *application,
                     GFile        **files,
                     gint           n_files,
                     const gchar   *hint)
{
	gint i;

	for (i = 0; i < n_files; i++)
		g37_multi_window_new_window (application, files[i]);
}

static void
g37_multi_window_init (G37multi_Window *object)
{
	object->priv = G_TYPE_INSTANCE_GET_PRIVATE (object, G37_MULTI_WINDOW_TYPE_APPLICATION, G37multi_WindowPrivate);
}

static void
g37_multi_window_finalize (GObject *object)
{
	G_OBJECT_CLASS (g37_multi_window_parent_class)->finalize (object);
}

static void
g37_multi_window_class_init (G37multi_WindowClass *klass)
{
	G_APPLICATION_CLASS (klass)->activate = g37_multi_window_activate;
	G_APPLICATION_CLASS (klass)->open = g37_multi_window_open;

	g_type_class_add_private (klass, sizeof (G37multi_WindowPrivate));

	G_OBJECT_CLASS (klass)->finalize = g37_multi_window_finalize;
}

G37multi_Window *
g37_multi_window_new (void)
{
	return g_object_new (g37_multi_window_get_type (),
	                     "application-id", "org.gnome.g37_multi_window",
	                     "flags", G_APPLICATION_HANDLES_OPEN,
	                     NULL);
}

