uni.addInterceptor({
  returnValue(res) {
    const isPromiseLike =
      res &&
      (typeof res === "object" || typeof res === "function") &&
      typeof res.then === "function";

    if (!isPromiseLike) {
      return res;
    }

    return new Promise((resolve, reject) => {
      res.then(([error, result]) => {
        if (error) {
          reject(error);
        } else {
          resolve(result);
        }
      });
    });
  },
});
