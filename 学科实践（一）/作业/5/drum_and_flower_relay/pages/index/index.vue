<template>
  <view>
    <view :class="classContain1Obj">
      <view class="box1">{{ pointer }}</view>
    </view>
    <button type="default" @click="TurnRound">击鼓传花</button>
  </view>
</template>

<script>
export default {
  data() {
    return {
      pointer: 0,
      classcontainer1: "container1",
      classContain1Obj: "",
    };
  },
  onLoad() {
    this.updateClassContain1Obj();
  },
  methods: {
    TurnRound() {
      this.pointer = (this.pointer + 1) % 9;
      this.updateClassContain1Obj();
    },
    updateClassContain1Obj() {
      this.classContain1Obj = `${this.classcontainer1} position-${this.pointer} animate`;
    },
  },
};
</script>

<style>
.container {
  display: flex;
  flex-direction: row;
  margin: 10px;
}

.container1 {
  display: flex;
  width: 600rpx;
  height: 600rpx;
  background-color: beige;
  margin: 10rpx auto;
  justify-content: center;
  align-items: center;
}

.box1 {
  width: 200rpx;
  height: 200rpx;
  background-color: fuchsia;
  border-radius: 50%;
  text-align: center;
  line-height: 200rpx;
  transition: transform $uni-animation-duration $uni-animation-timing-function;
}

.animate {
  animation: move $uni-animation-duration $uni-animation-timing-function;
}

@keyframes move {
  from {
    transform: scale(1);
  }
  to {
    transform: scale(1.1);
  }
}

.position-0 {
  justify-content: flex-start;
  align-items: flex-start;
}

.position-1 {
  justify-content: center;
  align-items: flex-start;
}

.position-2 {
  justify-content: flex-end;
  align-items: flex-start;
}

.position-3 {
  justify-content: flex-end;
  align-items: center;
}

.position-4 {
  justify-content: flex-end;
  align-items: flex-end;
}

.position-5 {
  justify-content: center;
  align-items: flex-end;
}

.position-6 {
  justify-content: flex-start;
  align-items: flex-end;
}

.position-7 {
  justify-content: flex-start;
  align-items: center;
}

.position-8 {
  justify-content: center;
  align-items: center;
}
</style>
