/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * g24-hello.c
 * Copyright (C) 2022 tiger <tiger@loongnix>
 * 
 * G24-Hello is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * G24-Hello is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "g24-hello.h"

#include <glib/gi18n.h>



/* For testing propose use the local (not installed) ui file */
/* #define UI_FILE PACKAGE_DATA_DIR"/ui/g24_hello.ui" */
#define UI_FILE "src/g24_hello.ui"
#define TOP_WINDOW "window"


G_DEFINE_TYPE (G24hello, g24_hello, GTK_TYPE_APPLICATION);

/* ANJUTA: Macro G24_HELLO_APPLICATION gets G24hello - DO NOT REMOVE */
struct _G24helloPrivate
{
	/* ANJUTA: Widgets declaration for g24_hello.ui - DO NOT REMOVE */
	GtkWidget* window;
};

/* Create a new window loading a file */
static void
g24_hello_new_window (GApplication *app,
                           GFile        *file)
{
	GtkWidget *window;

	GtkBuilder *builder;
	GError* error = NULL;

	G24helloPrivate *priv = G24_HELLO_APPLICATION(app)->priv;

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

	
	/* ANJUTA: Widgets initialization for g24_hello.ui - DO NOT REMOVE */
	priv->window = GTK_WIDGET (gtk_builder_get_object(builder, "window"));

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
g24_hello_activate (GApplication *application)
{
	g24_hello_new_window (application, NULL);
}

static void
g24_hello_open (GApplication  *application,
                     GFile        **files,
                     gint           n_files,
                     const gchar   *hint)
{
	gint i;

	for (i = 0; i < n_files; i++)
		g24_hello_new_window (application, files[i]);
}

static void
g24_hello_init (G24hello *object)
{
	object->priv = G_TYPE_INSTANCE_GET_PRIVATE (object, G24_HELLO_TYPE_APPLICATION, G24helloPrivate);
}

static void
g24_hello_finalize (GObject *object)
{
	G_OBJECT_CLASS (g24_hello_parent_class)->finalize (object);
}

static void
g24_hello_class_init (G24helloClass *klass)
{
	G_APPLICATION_CLASS (klass)->activate = g24_hello_activate;
	G_APPLICATION_CLASS (klass)->open = g24_hello_open;

	g_type_class_add_private (klass, sizeof (G24helloPrivate));

	G_OBJECT_CLASS (klass)->finalize = g24_hello_finalize;
}

G24hello *
g24_hello_new (void)
{
	return g_object_new (g24_hello_get_type (),
	                     "application-id", "org.gnome.g24_hello",
	                     "flags", G_APPLICATION_HANDLES_OPEN,
	                     NULL);
}

