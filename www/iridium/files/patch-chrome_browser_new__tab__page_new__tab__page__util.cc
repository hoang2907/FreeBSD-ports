--- chrome/browser/new_tab_page/new_tab_page_util.cc.orig	2022-10-05 07:34:01 UTC
+++ chrome/browser/new_tab_page/new_tab_page_util.cc
@@ -11,7 +11,7 @@
 
 namespace {
 bool IsOsSupportedForRecipe() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
