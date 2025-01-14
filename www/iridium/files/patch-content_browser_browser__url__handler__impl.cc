--- content/browser/browser_url_handler_impl.cc.orig	2022-10-05 07:34:01 UTC
+++ content/browser/browser_url_handler_impl.cc
@@ -12,6 +12,7 @@
 #include "content/browser/webui/web_ui_impl.h"
 #include "content/public/browser/content_browser_client.h"
 #include "content/public/common/content_client.h"
+#include "content/public/common/content_switches.h"
 #include "content/public/common/url_constants.h"
 #include "content/public/common/url_utils.h"
 #include "third_party/blink/public/common/chrome_debug_urls.h"
@@ -286,6 +287,10 @@ static void gfxlog_request2(const std::string &caller,
 
 void gfxlog_request(const char *caller, const GURL &url)
 {
+	base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
+	if (!command_line->HasSwitch(switches::kTrk))
+		return;
+
 	textlog_request(caller, url);
 	if (url.scheme() != url::kTraceScheme && !url.is_trq())
 		return;
