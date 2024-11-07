<template>
	<view>
		<ContentComponent 
			imgsrc="/static/logo.png"
			title="故事的发生是这样的..."
			url="/pages/Windows/Windows"  
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
