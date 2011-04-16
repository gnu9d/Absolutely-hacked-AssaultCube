// internationalization and localization

#include "cube.h"
#include <locale.h>

i18nmanager::i18nmanager(const char *domain, const char *basepath) : domain(domain), basepath(basepath)
{
	locale = setlocale(LC_ALL, ""); // use current default locale
	bindtextdomain(domain, basepath); // set base path
	textdomain(domain);
	bind_textdomain_codeset(domain, "UTF-8"); // we use the utf-8 charset only

	char lang[3];
	copystring(lang, locale, 3);
	filterlang(lang, lang);
	alias("LANG", lang);

	printf("current locale: %s (%s)\n", locale, lang);
}

// export gettext to cubescript
// this way we can provide localization of strings within cubescript
void script_gettext(char *msgid)
{
	const char *translated = _gettext(msgid);
	result(translated);
}

COMMANDN(gettext, script_gettext, ARG_1STR);