SUBDIRS = lib hstio cvos tables ctegen2 pkg
ACLOCAL_AMFLAGS = -I m4
EXTRA_DIST = \
	$(top_srcdir)/INSTALL.md \
	$(top_srcdir)/README.md \
	$(top_srcdir)/LICENSE.txt \
	$(top_srcdir)/include \
	$(top_srcdir)/hstio \
	$(top_srcdir)/cvos \
	$(top_srcdir)/tables \
	$(top_srcdir)/ctegen2 \
	$(top_srcdir)/pkg \
	$(top_srcdir)/bootstrap \
	$(top_srcdir)/.ci \
	$(top_srcdir)/.version

BUILT_SOURCES = $(top_srcdir)/.version
$(top_srcdir)/.version:
	echo '$(VERSION)' > $@-t
	mv $@-t $@
dist-hook:
	echo '$(VERSION)' > $(distdir)/.tarball-version
