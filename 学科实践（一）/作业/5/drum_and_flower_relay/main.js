import App from "./App";

// Common imports
// #ifndef VUE3
import Vue from "vue";
import "./uni.promisify.adaptor";

// Vue 2 specific configuration
Vue.config.productionTip = false;
App.mpType = "app";

const app = new Vue({
  ...App,
});
app.$mount();
// #endif

// Vue 3 specific configuration
// #ifdef VUE3
import { createSSRApp } from "vue";

export function createApp() {
  const app = createSSRApp(App);
  return {
    app,
  };
}
// #endif
