"use strict";
const common_vendor = require("../common/vendor.js");
const _sfc_main = {
  props: {
    imgsrc: {
      type: String,
      required: true
    },
    title: {
      type: String,
      required: true
    },
    url: {
      type: String,
      required: true
    }
  },
  methods: {
    NavigateToWindows() {
      common_vendor.index.switchTab({
        url: this.url
        // 使用传入的 URL
      });
    }
  }
};
function _sfc_render(_ctx, _cache, $props, $setup, $data, $options) {
  return {
    a: $props.imgsrc,
    b: common_vendor.t($props.title),
    c: common_vendor.o((...args) => $options.NavigateToWindows && $options.NavigateToWindows(...args))
  };
}
const Component = /* @__PURE__ */ common_vendor._export_sfc(_sfc_main, [["render", _sfc_render]]);
wx.createComponent(Component);
