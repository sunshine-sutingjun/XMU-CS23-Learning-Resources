<template>
	<view>
		<ContentComponent 
			imgsrc="/static/Huawei.png"
			title="没有伤痕累累，
			哪来皮糙肉厚，
			英雄自古多磨难。
			回头看，
			崎岖坎坷；
			向前看，
			永不言弃。"
			url="/pages/index/index"  
		>
		
		</ContentComponent>

	</view>
</template>

<script>
	import ContentComponent from '@/components/ContentComponent.vue';

	export default {
		components: {
			ContentComponent
		}
	}
</script>
